#include "pch.h"
#include "Star.h"
#include <random>

namespace Neno
{
    void Star::draw()
    {
        glPushMatrix();
        
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, starColor_);
        
        glTranslatef(transform_.position.x, transform_.position.y, transform_.position.z);

        glRotatef(transform_.rotation.z, 0, 0, 1);
        glRotatef(transform_.rotation.x, 1, 0, 0);
        glRotatef(transform_.rotation.y, 0, 1, 0);
        glutSolidCube(1);

        glPopMatrix();
    }

    void Star::update()
    {
        Vector3 rotate((*rand_)(*mt_), (*rand_)(*mt_), (*rand_)(*mt_));
        transform_.rotation += rotate;

        if(transform_.rotation.x >= 360)
        {
            transform_.rotation.x = 0;
        }

        if (transform_.rotation.y >= 360)
        {
            transform_.rotation.y = 0;
        }

        if (transform_.rotation.z >= 360)
        {
            transform_.rotation.z = 0;
        }
    }
}