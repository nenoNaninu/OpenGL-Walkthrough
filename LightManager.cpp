#include "pch.h"
#include "LightManager.h"

namespace Neno
{
    void LightManager::update()
    {
        //do nothing
    }

    void LightManager::draw()
    {
        glLightfv(GL_LIGHT1, GL_DIFFUSE, blue);
        glLightfv(GL_LIGHT1, GL_SPECULAR, blue);
        glLightfv(GL_LIGHT0, GL_POSITION, light0Pos_);
        glLightfv(GL_LIGHT1, GL_POSITION, light0Pos_);
    }
}