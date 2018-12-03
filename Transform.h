#pragma once

#include "Vector3.h"

namespace Neno
{
    struct Transform
    {
        Vector3 position = {};
        //便利関数は後で作ろう。
        //Vector3 getForward(){};
        //Vector3 getUpward(){};
        //Vector3 getRight(){};
        Vector3 rotation = {};
    };
}

