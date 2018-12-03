#pragma once

#include "Object.h"
#include <iostream>

namespace Neno
{
    //光源管理するためのクラス
    class LightManager : public Object
    {
        GLfloat light0Pos_[4] = {0, -50, 0, 1};
        GLfloat blue[4] = {0.0, 0, 1.0, 1.0};
    public:
        LightManager()
        {
            glEnable(GL_LIGHTING);
            glEnable(GL_LIGHT0);
            glEnable(GL_LIGHT1);
        };

        void update() override;

        void draw() override;
    };

};
