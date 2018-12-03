#include "pch.h"
#include "Player.h"
#include "InputManager.h"

namespace Neno
{
    void Player::draw()
    {
        static float posy;
        glLoadIdentity();
        gluPerspective(30, cameraAspect_, 1.0, 1000.0);
       

        gluLookAt(transform_.position.x, transform_.position.y, transform_.position.z, 
            transform_.position.x, transform_.position.y + 100, transform_.position.z, 
            0.0, 0.0, 1.0);
    }

    //とりあえず移動だけ。回転は後回し
    void Player::update()
    {        

        if (InputManager::checkKeyFlag('w'))
        {
            transform_.position.y += moveSpeed_;
        }

        if (InputManager::checkKeyFlag('a'))
        {
            transform_.position.x -= moveSpeed_;
        }

        if (InputManager::checkKeyFlag('s'))
        {
            transform_.position.y -= moveSpeed_;
        }

        if (InputManager::checkKeyFlag('d'))
        {
            transform_.position.x += moveSpeed_;
        }

        if(InputManager::checkKeyFlag('z'))
        {
            transform_.position.z += moveSpeed_;
        }

        if(InputManager::checkKeyFlag('x'))
        {
            transform_.position.z -= moveSpeed_;
        }
    }

    void Player::setNewCameraAspect(double newAspect)
    {
        cameraAspect_ = newAspect;
    }
}

