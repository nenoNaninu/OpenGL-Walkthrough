#include "pch.h"
#include "Player.h"
#include "InputManager.h"
#include <cmath>
#include <iostream>
#include "Utility.h"

namespace Neno
{
    void Player::draw()
    {

        glLoadIdentity();
        gluPerspective(30, cameraAspect_, 1.0, 1000.0);

        gluLookAt(transform_.position.x,
                  transform_.position.y,
                  transform_.position.z,
                  transform_.position.x + currentLookDirection_.x,
                  transform_.position.y + currentLookDirection_.y,
                  transform_.position.z + currentLookDirection_.z,
                  0.0, 0.0, 1.0);
    }

    //とりあえず移動だけ。回転は後回し
    void Player::update()
    {
        using Utility::deg2rad;

        if (InputManager::checkKeyFlag('w'))
        {
            transform_.position.x += currentLookDirection_.x * moveSpeed_;
            transform_.position.y += currentLookDirection_.y * moveSpeed_;
        }

        if (InputManager::checkKeyFlag('s'))
        {
            transform_.position.x -= currentLookDirection_.x * moveSpeed_;
            transform_.position.y -= currentLookDirection_.y * moveSpeed_;
        }

        if (InputManager::checkKeyFlag('a'))
        {
            double panRad = deg2rad(panAngle_ + 90.0);
            double tiltRad = deg2rad(tiltAngle_);
            double costilt = std::cos(tiltRad);
            transform_.position.x -= std::sin(panRad) * costilt * moveSpeed_;
            transform_.position.y -= std::cos(panRad) * costilt * moveSpeed_;
        }

        if (InputManager::checkKeyFlag('d'))
        {
            double panRad = deg2rad(panAngle_ + 90.0);
            double tiltRad = deg2rad(tiltAngle_);
            double costilt = std::cos(tiltRad);
            transform_.position.x += std::sin(panRad) * costilt * moveSpeed_;
            transform_.position.y += std::cos(panRad) * costilt * moveSpeed_;
        }

        if (InputManager::checkKeyFlag('z'))
        {
            transform_.position.z += moveSpeed_;
        }

        if (InputManager::checkKeyFlag('x'))
        {
            transform_.position.z -= moveSpeed_;
        }
    }

    void Player::setNewCameraAspect(double newAspect)
    {
        cameraAspect_ = newAspect;
    }

    void Player::inputFromMouse(int button, int state, int x, int y)
    {
        switch (button)
        {
            case GLUT_LEFT_BUTTON:
                switch (state)
                {
                    case GLUT_DOWN:
                        mouseDownFlag_ = true;
                        prevMousePosX_ = x;
                        prevMousePosY_ = y;
                        break;
                    case GLUT_UP:
                        mouseDownFlag_ = false;

                        break;
                }
            default:
                break;
        }
    }

    //1ピクセルあたり0.1度回転するとする.
    void Player::inputFromMouseMotion(int x, int y)
    {
        if (mouseDownFlag_)
        {
            double dx = (x - prevMousePosX_) * 0.2;
            double dy = (y - prevMousePosY_) * -0.2;

            panAngle_ += dx;
            tiltAngle_ += dy;

            //角度の制限。
            if (panAngle_ < -180)
            {
                panAngle_ += 360;
            }

            if (180 < panAngle_)
            {
                panAngle_ -= 360;
            }

            if (tiltAngle_ < -85)
            {
                tiltAngle_ = -85;
            }

            if (85 < tiltAngle_)
            {
                tiltAngle_ = 85;
            }

            prevMousePosX_ = x;
            prevMousePosY_ = y;

            using Utility::deg2rad;

            double panRad = deg2rad(panAngle_);
            double tiltRad = deg2rad(tiltAngle_);
            double costilt = std::cos(tiltRad);
            currentLookDirection_.x = std::sin(panRad) * costilt;
            currentLookDirection_.y = std::cos(panRad) * costilt;
            currentLookDirection_.z = std::sin(tiltRad);
        }
    }
}

