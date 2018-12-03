#pragma once
#include "Object.h"
#include "Vector3.h"

namespace Neno
{
    //fpsなのでここにカメラとかも扱う。
    class Player : public Object
    {
    private:
        double cameraAspect_;
        double moveSpeed_ = 0.2;

        //パンは左右 -180~180で動く。超えたら-180と180を接続
        double panAngle_ = 0;

        //チルは上下 -85~85
        double tiltAngle_ = 0;


        Vector3 currentLookDirection_= Vector3(0,1,0);
        int prevMousePosX_,prevMousePosY_;
        bool mouseDownFlag_ = false;
    public:
        void draw() override;
        Player(double cameraAspect) :cameraAspect_(cameraAspect) {};
        void setNewCameraAspect(double newAspect);
        void update() override;
        void inputFromMouse(int button,int state,int x, int y);
        void inputFromMouseMotion(int x, int y);
    };
}
