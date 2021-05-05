/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Vec3
*/

#pragma once

template <typename TValue>
class Vec3
{
    Vec3(TValue x = 0, TValue y = 0, TValue z = 0) : x(x), y(y), z(z)
    {
    }

    Vec3 &operator+=(const Vec3 &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
    }

    Vec3 &operator-=(const Vec3 &other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
    }

    Vec3 operator+(const Vec3 &other)
    {
        return Vec3(other.x + x, other.y + y, other.z + z);
    }

    Vec3 operator-(const Vec3 &other)
    {
        return Vec3(other.x - x, other.y - y, other.z - z);
    }

    bool operator==(const Vec3 &other) const
    {
        return (x == other.x && y == other.y && z == other.z);
    }

    void set(TValue x, TValue y, TValue z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    TValue x;
    TValue y;
    TValue z;
};

using Vec3d = Vec3<double>;
using Vec3f = Vec3<float>;
using Vec3i = Vec3<int>;
using Vec3u = Vec3<unsigned int>;
