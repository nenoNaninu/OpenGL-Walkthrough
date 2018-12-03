#include "pch.h"
#include "RootManager.h"
#include "Player.h"
#include "Utility.h"

namespace Neno
{
    void RootManager::resize(int w, int h)
    {
        glViewport(0, 0, w, h);
        player_->setNewCameraAspect((double)w / (double)h);
    }

    void RootManager::display()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //バッファの消去
        lightManager_->update();
        lightManager_->draw();

        player_->update();
        player_->draw();

        stageManager_->update();
        stageManager_->draw();

        Debug::Display();
        glutSwapBuffers(); //glutInitDisplayMode(GLUT_DOUBLE)でダブルバッファリングを利用可
    }

    void RootManager::idle()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        player_->update();
        player_->draw();
        stageManager_->update();
        stageManager_->draw();
        Debug::Display();
        glutSwapBuffers(); //glutInitDisplayMode(GLUT_DOUBLE)でダブルバッファリングを利用可
    }

    void RootManager::inputFromKeyboard(unsigned char key, int x, int y)
    {

    }

    void RootManager::inputFromMouse(int button, int state, int x, int y)
    {

    }

}
