#pragma once
#include "Object.h"

namespace Neno
{
    //fpsなのでここにカメラとかも扱う。
    class Player : public Object
    {
    private:
        double cameraAspect_;
        double moveSpeed_ = 0.2;
    public:
        void draw() override;
        Player(double cameraAspect) :cameraAspect_(cameraAspect) {};
        void setNewCameraAspect(double newAspect);
        void update() override;
    };
}
