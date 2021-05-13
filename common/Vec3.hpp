/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Vec3
*/

#pragma once

template <typename TValue>
struct Vec3
{
    Vec3(TValue x = 0, TValue y = 0, TValue z = 0) : x(x), y(y), z(z)
    {
    }

    Vec3(const Vec3 &other) : Vec3(other.x, other.y, other.z) {}

    Vec3 &operator+=(const Vec3 &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;

        return *this;
    }

    Vec3 &operator-=(const Vec3 &other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;

        return *this;
    }

    Vec3 operator+(const Vec3 &other)
    {
        return Vec3(other.x + x, other.y + y, other.z + z);
    }

    Vec3 operator-(const Vec3 &other)
    {
        return Vec3(other.x - x, other.y - y, other.z - z);
    }

    Vec3 &operator*=(TValue factor)
    {
        x *= factor;
        y *= factor;
        z *= factor;

        return *this;
    }


    Vec3 &operator/=(TValue factor)
    {
        if (factor) {
            x /= factor;
            y /= factor;
            z /= factor;
        } else {
            x = y = z = 0;
        }
        return *this;
    }

    Vec3 operator*(TValue factor)
    {
        return Vec3(x * factor, y * factor, z * factor);
    }

    Vec3 operator/(TValue op)
    {
        if (op == 0) {
            return Vec3();
        }
        return Vec3(x / op, y / op, z / op);
    }

    bool operator==(const Vec3 &other) const
    {
        return (x == other.x && y == other.y && z == other.z);
    }

    void set(TValue _x, TValue _y, TValue _z)
    {
        this->x = _x;
        this->y = _y;
        this->z = _z;
    }

    void operator=(const Vec3 &other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
    }

    TValue x;
    TValue y;
    TValue z;
};

using Vec3d = Vec3<double>;
using Vec3f = Vec3<float>;
using Vec3i = Vec3<int>;
using Vec3u = Vec3<unsigned int>;
