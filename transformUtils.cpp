#include "transformUtils.hpp"
//#include "math.h"

Transform::Transform()
{
    position = Vec3(0,0,0);
    rotation = Vec3(0,0,0);
    scale = Vec3(1,1,1);
};

Transform::~Transform()
{

};

Transform::Transform(Vec3 pos, Vec3 rot, Vec3 sca)
{
    position = pos;
    rotation = rot;
    scale = sca;
};

Vec3 Transform::ForwardVec()
{
    //https://gamedev.stackexchange.com/questions/190054/how-to-calculate-the-forward-up-right-vectors-using-the-rotation-angles
    
    Vec3 forwardVec{
        cosf(rotation.x / 180.0f * 3.14159f) * sinf(rotation.y / 180.0f * 3.14159f),
        -sinf(rotation.x / 180.0f * 3.14159f),
        cosf(rotation.x / 180.0f * 3.14159f) * cosf(rotation.y / 180.0f * 3.14159f)
    };

    forwardVec.Normalize();
    forwardVec.z *= -1.0f;
    return (forwardVec);
};

Vec3 Transform::RightVec()
{
    Vec3 rightVec{
        cosf(rotation.y / 180.0f * 3.14159f),
        0,
        -sinf(rotation.y / 180.0f * 3.14159f)
    };

    rightVec.Normalize();
    rightVec.z *= -1.0f;
    return rightVec;
};

Vec3 Transform::UpVec()
{
    Vec3 forwardVec{
        cosf(rotation.x / 180.0f * 3.14159f) * sinf(rotation.y / 180.0f * 3.14159f),
        -sinf(rotation.x / 180.0f * 3.14159f),
        cosf(rotation.x / 180.0f * 3.14159f) * cosf(rotation.y / 180.0f * 3.14159f)
    };

    forwardVec.Normalize();

    Vec3 rightVec{
        cosf(rotation.y / 180.0f * 3.14159f),
        0,
        -sinf(rotation.y / 180.0f * 3.14159f)
    };

    rightVec.Normalize();

    Vec3 upVec = Cross(forwardVec, rightVec);

    upVec.Normalize();

    upVec.z *= -1.0f;
    return upVec;
};


//tutorial for a look at function
//https://stackoverflow.com/questions/8208789/3d-vector-x-y-z-look-at-vector
void Transform::LookAt(Transform t)
{
    Vec3 dir = position - t.position;
    float xzdist = sqrtf((dir.x * dir.x) + (dir.z * dir.z));
    float y = -atan2f(dir.x, dir.z);
    float x = atan2f(dir.y, xzdist);
    rotation = Vec3(x * (180.0f / 3.14159f), y * (180.0f / 3.14159f), 0.0f);
};

void Transform::LookAt(Vec3 p)
{
    Vec3 dir = position - p;
    float xzdist = sqrtf((dir.x * dir.x) + (dir.z * dir.z));
    float y = -atan2f(dir.x, dir.z);
    float x = atan2f(dir.y, xzdist);
    rotation = Vec3(x * (180.0f / 3.14159f), y * (180.0f / 3.14159f), 0.0f);
};