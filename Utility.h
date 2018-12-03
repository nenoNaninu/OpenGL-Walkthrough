#pragma once
#include "pch.h"

namespace Neno
{
    namespace Debug
    {
        void Ground(void) {
            double ground_max_x = 300.0;
            double ground_max_y = 300.0;
            glColor3d(0.8, 0.8, 0.8);  // 大地の色
            glBegin(GL_LINES);
            for (double ly = -ground_max_y; ly <= ground_max_y; ly += 10.0) {
                glVertex3d(-ground_max_x, ly, 0);
                glVertex3d(ground_max_x, ly, 0);
            }
            for (double lx = -ground_max_x; lx <= ground_max_x; lx += 10.0) {
                glVertex3d(lx, ground_max_y, 0);
                glVertex3d(lx, -ground_max_y, 0);
            }
            glEnd();
        }


        void Display(void) {

            //球
            glPushMatrix();
            glColor3d(1.0, 0.0, 0.0); 
            glTranslated(0.0, 10.0, 20.0);
            glutSolidSphere(4.0, 20, 20);//引数：(半径, Z軸まわりの分割数, Z軸に沿った分割数)
            glPopMatrix();

            //立方体
            glPushMatrix();
            glColor3d(0.0, 1.0, 0.0);
            glTranslated(-20.0, 0.0, 20.0);
            glutSolidCube(10.0);//引数：(一辺の長さ)
            glPopMatrix();

            //円錐
            glPushMatrix();
            glColor3d(0.0, 0.0, 1.0);//色の設定
            glTranslated(20.0, 100.0, 0.0);//平行移動値の設定
            glutSolidCone(5.0, 10.0, 20, 20);//引数：(半径, 高さ, Z軸まわりの分割数, Z軸に沿った分割数)
            glPopMatrix();

            Ground();
        }
    }
}

