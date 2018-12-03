#pragma once
#include "Vector3.h"
#include "Transform.h"

namespace Neno
{
    class Object
    {
    public:
        bool isActive_ = true;
        Transform transform_ = {};
        virtual void moveAt(Vector3 vector3);
        virtual void move2Direction(Vector3 direction);
        virtual void rotate(Vector3 rotation);
        virtual void update() = 0;
        virtual void draw() = 0;
    };
}

