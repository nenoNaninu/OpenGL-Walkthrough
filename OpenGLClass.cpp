// OpenGLClass.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
#include "RootManager.h"
#include "InputManager.h"


std::unique_ptr<Neno::RootManager> rootManager;

void display()
{
    rootManager -> display();
}

void idle()
{
    rootManager -> idle();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

void mouse(int button, int state, int x, int y)
{
    rootManager -> inputFromMouse(button, state, x, y);
}


void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case '\033':  /* '\033' は ESC の ASCII コード */
//        glutLeaveMainLoop();
        exit(0);
    default:
        break;
    }
    std::cout << "registrate" << key << std::endl;
    InputManager::registrateInput(key);
}

void keybordUp(unsigned char key, int x, int y)
{
    std::cout << "unregistrate" << key << std::endl;
    InputManager::unregistrateInput(key);
}

void resize(int w, int h)
{
    rootManager -> resize(w, h);
}

void mouseMotion(int x, int y)
{
    rootManager ->inputFromMouseMotion(x,y);
}

int main(int argc, char *argv[])
{
    glutInitWindowSize(640, 480);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keybordUp);
    glutIdleFunc(idle);
    init();

    rootManager = std::make_unique<Neno::RootManager>(640, 480);

    glutMainLoop();
    return 0;
}
