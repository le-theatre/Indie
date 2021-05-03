#pragma once

namespace ecs {

template <typename TValue>
class Vec3 {
    TValue x;
    TValue y;
    TValue z;

    Vec3(TValue _x = 0, TValue _y = 0, TValue _z = 0) :
        x(_x), y(_y), z(_z)
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

    bool operator==(const Vec3 &other) const
    {
        return (x == other.x && y == other.y && z == other.z);
    }


};

using Vec3d = Vec3<double>;
using Vec3f = Vec3<float>;
using Vec3i = Vec3<int>;
using Vec3u = Vec3<unsigned int>;

}
