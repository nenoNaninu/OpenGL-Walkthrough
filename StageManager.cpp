#include "pch.h"
#include "StageManager.h"

namespace Neno
{
    void StageManager::update()
    {
        //星の回転
        for (int i = 0, n = starVector_.size(); i < n; i++)
        {
            Star *star = starVector_[i].get();
            star->update();
        }
    }

    void StageManager::draw()
    {
        //スカイボックスの描画
        drawSkyBox();

        //星の描画
        for (int i = 0, n = starVector_.size(); i < n; i++)
        {
            Star *star = starVector_[i].get();
            star->draw();
        }
    }

    void StageManager::drawSkyBox()
    {
        static const GLfloat color[] = {1.0, 1.0, 1.0, 1.0};  /* 材質 (色) */

        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
        const double skyboxEdgeLength = 200;
        //上
        glEnable(GL_TEXTURE_2D);
        glNormal3d(0.0, 0.0, 1.0);
        glBegin(GL_QUADS);
        glTexCoord2d(0.0, 1.0);
        glVertex3d(-skyboxEdgeLength, -skyboxEdgeLength, skyboxEdgeLength);
        glTexCoord2d(1.0, 1.0);
        glVertex3d(skyboxEdgeLength, -skyboxEdgeLength, skyboxEdgeLength);
        glTexCoord2d(1.0, 0.0);
        glVertex3d(skyboxEdgeLength, skyboxEdgeLength, skyboxEdgeLength);
        glTexCoord2d(0.0, 0.0);
        glVertex3d(-skyboxEdgeLength, skyboxEdgeLength, skyboxEdgeLength);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        //下
        glEnable(GL_TEXTURE_2D);
        glNormal3d(0.0, 0.0, 1.0);
        glBegin(GL_QUADS);
        glTexCoord2d(0.0, 1.0);
        glVertex3d(-skyboxEdgeLength, -skyboxEdgeLength, -skyboxEdgeLength);
        glTexCoord2d(1.0, 1.0);
        glVertex3d(skyboxEdgeLength, -skyboxEdgeLength, -skyboxEdgeLength);
        glTexCoord2d(1.0, 0.0);
        glVertex3d(skyboxEdgeLength, skyboxEdgeLength, -skyboxEdgeLength);
        glTexCoord2d(0.0, 0.0);
        glVertex3d(-skyboxEdgeLength, skyboxEdgeLength, -skyboxEdgeLength);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        //下
        glEnable(GL_TEXTURE_2D);
        glNormal3d(0.0, 0.0, 1.0);
        glBegin(GL_QUADS);
        glTexCoord2d(0.0, 1.0);
        glVertex3d(-skyboxEdgeLength, -skyboxEdgeLength, skyboxEdgeLength);
        glTexCoord2d(1.0, 1.0);
        glVertex3d(-skyboxEdgeLength, -skyboxEdgeLength, -skyboxEdgeLength);
        glTexCoord2d(1.0, 0.0);
        glVertex3d(-skyboxEdgeLength, skyboxEdgeLength, -skyboxEdgeLength);
        glTexCoord2d(0.0, 0.0);
        glVertex3d(-skyboxEdgeLength, skyboxEdgeLength, skyboxEdgeLength);
        glEnd();
        glDisable(GL_TEXTURE_2D);


        //下
        glEnable(GL_TEXTURE_2D);
        glNormal3d(0.0, 0.0, 1.0);
        glBegin(GL_QUADS);
        glTexCoord2d(0.0, 1.0);
        glVertex3d(-skyboxEdgeLength, skyboxEdgeLength, skyboxEdgeLength);
        glTexCoord2d(1.0, 1.0);
        glVertex3d(-skyboxEdgeLength, skyboxEdgeLength, -skyboxEdgeLength);
        glTexCoord2d(1.0, 0.0);
        glVertex3d(skyboxEdgeLength, skyboxEdgeLength, -skyboxEdgeLength);
        glTexCoord2d(0.0, 0.0);
        glVertex3d(skyboxEdgeLength, skyboxEdgeLength, skyboxEdgeLength);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        //下
        glEnable(GL_TEXTURE_2D);
        glNormal3d(0.0, 0.0, 1.0);
        glBegin(GL_QUADS);
        glTexCoord2d(0.0, 1.0);
        glVertex3d(skyboxEdgeLength, -skyboxEdgeLength, skyboxEdgeLength);
        glTexCoord2d(1.0, 1.0);
        glVertex3d(skyboxEdgeLength, -skyboxEdgeLength, -skyboxEdgeLength);
        glTexCoord2d(1.0, 0.0);
        glVertex3d(skyboxEdgeLength, skyboxEdgeLength, -skyboxEdgeLength);
        glTexCoord2d(0.0, 0.0);
        glVertex3d(skyboxEdgeLength, skyboxEdgeLength, skyboxEdgeLength);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        //下
        glEnable(GL_TEXTURE_2D);
        glNormal3d(0.0, 0.0, 1.0);
        glBegin(GL_QUADS);
        glTexCoord2d(0.0, 1.0);
        glVertex3d(-skyboxEdgeLength, -skyboxEdgeLength, skyboxEdgeLength);
        glTexCoord2d(1.0, 1.0);
        glVertex3d(-skyboxEdgeLength, -skyboxEdgeLength, -skyboxEdgeLength);
        glTexCoord2d(1.0, 0.0);
        glVertex3d(skyboxEdgeLength, -skyboxEdgeLength, -skyboxEdgeLength);
        glTexCoord2d(0.0, 0.0);
        glVertex3d(skyboxEdgeLength, -skyboxEdgeLength, skyboxEdgeLength);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
}