#pragma once
#include "Player.h"
#include <memory>
#include "StageManager.h"
#include "LightManager.h"

namespace Neno
{
    class RootManager
    {
    private:
        std::unique_ptr<Player> player_;
        std::unique_ptr<StageManager> stageManager_;
        std::unique_ptr<LightManager> lightManager_;
    public:
        void display();
        void resize(int w, int h);
        void idle();
        void inputFromKeyboard(unsigned char key, int x, int y);
        void inputFromMouse(int button, int state, int x, int y);
        RootManager(int w, int h)
        {
            player_ = std::make_unique<Player>((double)w / (double)h);
            stageManager_ = std::make_unique<StageManager>();
            lightManager_ = std::make_unique<LightManager>();
            glClearColor(0.0, 229.0 / 255, 238 / 255.0, 1);
        }
    };
}
