/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Vec2
*/

#pragma once

template <typename TValue>
struct Vec2
{
    Vec2(TValue x = 0, TValue y = 0) : x(x), y(y)
    {
    }

    Vec2 &operator+=(const Vec2 &other)
    {
        x += other.x;
        y += other.y;
    }

    Vec2 &operator-=(const Vec2 &other)
    {
        x -= other.x;
        y -= other.y;
    }

    Vec2 operator+(const Vec2 &other)
    {
        return Vec2(other.x + x, other.y + y);
    }

    Vec2 operator-(const Vec2 &other)
    {
        return Vec2(other.x - x, other.y - y);
    }

    bool operator==(const Vec2 &other) const
    {
        return (x == other.x && y == other.y);
    }

    void set(TValue x, TValue y)
    {
        this->x = x;
        this->y = y;
    }

    TValue x;
    TValue y;
};

using Vec2d = Vec2<double>;
using Vec2f = Vec2<float>;
using Vec2i = Vec2<int>;
using Vec2u = Vec2<unsigned int>;
