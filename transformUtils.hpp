#pragma once

#include "vectorUtils.hpp"

class Transform
{
    public:

    Vec3 position;
    Vec3 rotation;
    Vec3 scale;
    
    Vec3 ForwardVec();

    Vec3 RightVec();

    Vec3 UpVec();

    void LookAt(Transform t);
    void LookAt(Vec3 p);
    
    Transform();
    Transform(Vec3 pos, Vec3 rot, Vec3 sca);

    ~Transform();
};
