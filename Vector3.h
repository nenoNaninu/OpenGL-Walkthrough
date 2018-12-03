#pragma once

namespace Neno
{
    struct Vector3
    {
    public:
        float x, y, z;

        Vector3()
        {
            x = 0;
            y = 0;
            z = 0;
        }

        Vector3(float x, float y, float z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        const Vector3 operator+(const Vector3 &other) const
        {
            Vector3 answer;
            answer.x = this->x + other.x;
            answer.y = this->y + other.y;
            answer.z = this->z + other.z;
            return answer;
        }

        Vector3 &operator+=(const Vector3 &other)
        {
            *this = *this + other;
            return *this;
        }


    };
}

