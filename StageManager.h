#pragma once

#include "Object.h"
#include <vector>
#include <memory>
#include "Star.h"
#include "pch.h"

namespace Neno
{
    class StageManager : public Object
    {
    private:
        const int textureWidth_ = 512;
        const int textureHeight_ = 512;
        std::vector<std::unique_ptr<Star>> starVector_;

        //スカイボックス用のテクスチャ。512x512で固定。
        const std::string textureName = "../spaceTexture512.data";

    public:
        void update() override;

        void draw() override;

        void drawSkyBox();

        StageManager()
        {
            GLubyte texture[textureHeight_][textureWidth_][3];
            FILE *fp;

            /* テクスチャ画像の読み込み */
            if ((fp = fopen(textureName.c_str(), "rb")) != NULL)
            {
                fread(texture, sizeof texture, 1, fp);
                fclose(fp);
            } else
            {
                perror(textureName.c_str());
            }

            glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

            /* テクスチャの割り当て */
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth_, textureHeight_, 0,
                         GL_RGB, GL_UNSIGNED_BYTE, texture);

            /* テクスチャを拡大・縮小する方法の指定 */
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

            starVector_.reserve(1000);
            for (int x = -5; x < 5; x++)
            {
                for (int y = -5; y < 5; y++)
                {
                    for (int z = -5; z < 5; z++)
                    {
                        starVector_.push_back(std::make_unique<Star>(x * 10.0, y * 10.0, z * 10.0));
                    }
                }
            }
        }
    };

}
