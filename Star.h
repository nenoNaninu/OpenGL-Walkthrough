#pragma once

#include "Object.h"
#include <random>
#include <memory>

namespace Neno
{
    //とりあえずcudeくるくる回しておく
    //あとでテクスチャとか
    class Star : public Object
    {
    private:
        std::random_device rd_;
        std::unique_ptr<std::mt19937> mt_;
        std::unique_ptr<std::uniform_real_distribution<float>> rand_;
        GLfloat starColor_[4] = {205 / 255.0, 133 / 255.0, 63 / 255.0, 1.0};

    public:
        void update() override;

        void draw() override;

        Star(float x, float y, float z)
        {
            transform_.position.x = x;
            transform_.position.y = y;
            transform_.position.z = z;
            mt_ = std::make_unique<std::mt19937>(rd_());
            rand_ = std::make_unique<std::uniform_real_distribution<float>>(0, 1.2);
        }
    };
}
