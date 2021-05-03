#pragma once

#include "Vec3.hpp"

namespace ecs {

struct Transform {
    Vec3f position;
    Vec3f scale;
    Vec3f rotation;
};

}
