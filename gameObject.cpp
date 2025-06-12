#include "gameObject.hpp"

GameObject::GameObject()
{
    
};

GameObject::~GameObject()
{

};

void Actor::Awake(){};
void Actor::Start(){};
void Actor::Update(){ if(!active){return;} };
void Actor::FixedUpdate(){ if(!active){return;} };
void Actor::LateUpdate(){ if(!active){return;} };
void Actor::OnEnable(){};
void Actor::OnDisable(){};
void Actor::OnDestroy(){};

void Actor::SetEnabled(bool onoff)
{ 
    if(active == true && onoff == false)
    {
        OnDisable();
        active = false;
    }else if(active == false && onoff == true)
    {
        OnEnable();
        active = true;
    }
};
void Actor::HandleCollisionEvent(){};

Actor::Actor() : GameObject()
{

};

Actor::~Actor()
{

};