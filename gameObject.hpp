#pragma once
#include "transformUtils.hpp"

//Objects that exist in the game world
class GameObject
{
    public:
    Transform transform;
    bool active;
    GameObject();
    virtual ~GameObject();
};

class Actor : public GameObject
{
    protected:
    virtual void Awake();
    virtual void Start();
    virtual void Update();
    virtual void FixedUpdate();
    virtual void LateUpdate();
    virtual void OnEnable();
    virtual void OnDisable();
    virtual void OnDestroy();

    public:
    void SetEnabled(bool onoff);
    virtual void HandleCollisionEvent();

    Actor();
    ~Actor();
};