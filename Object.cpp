#include "pch.h"
#include "Object.h"

namespace Neno
{
    void Object::moveAt(Vector3 vector3)
    {
        transform_.position = vector3;
    }

    void Object::move2Direction(Vector3 direction)
    {
        transform_.position += direction;
    }


    void Object::rotate(Vector3 rotation)
    {
        transform_.rotation = rotation;
    }

}