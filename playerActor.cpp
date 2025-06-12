#include "playerActor.hpp"
#include "vectorUtils.hpp"

#pragma region FPSPlayer
void FPSPlayer::Update()
{
    Controller& controller = Controller::GetController();

    if(controller.ButtonState(Input_Cross) == held)
    { 
        VCam.transform.rotation += Vec3(0.5f, 0.0f, 0.0f);
        if(VCam.transform.rotation.x > 60.0f)
        {
            VCam.transform.rotation.x = 60.0f;
        }
    }
    if(controller.ButtonState(Input_Triangle) == held)
    { 
        VCam.transform.rotation += Vec3(-0.5f, 0.0f, 0.0f);
        if(VCam.transform.rotation.x < -60.0f)
        {
            VCam.transform.rotation.x = -60.0f;
        }
    }
    if(controller.ButtonState(Input_Square) == held)
    { 
        VCam.transform.rotation += Vec3(0.0f, -1.5f, 0.0f);
    }
    if(controller.ButtonState(Input_Circle) == held)
    { 
        VCam.transform.rotation += Vec3(0.0f, 1.5f, 0.0f);
    }
    Vector2 stick = controller.StickState();
    if(stick == Vector2Zero){ moving = false; }else{ moving = true; }
    if(controller.ButtonState(Input_L) == held){ zooming = true; }else{ zooming = false; }
    if(controller.ButtonState(Input_Down) == press){ crouching = !crouching; }

    Vec3 f = (Cross(VCam.transform.RightVec(), Vector3Up));
    Vec3 r = (Cross(VCam.transform.ForwardVec(), Vector3Up));
    Vec3 moveVector = (f * stick.y) + (r * stick.x);

    moveVector.Normalize();
    moveVector *= 2.0f;
    transform.position += moveVector * DeltaTime();

    if(zooming){ FOV = LerpFloat(FOV, zoomFOV, 4 * DeltaTime()); }else{ FOV = LerpFloat(FOV, normalFOV, 4 * DeltaTime()); }
    VCam.FOV = FOV;

    if(crouching){ cameraYOffset = LerpFloat(cameraYOffset, cameraYOffsetCrouch, 4 * DeltaTime());}else{ cameraYOffset = LerpFloat(cameraYOffset, cameraYOffsetNormal, 4 * DeltaTime());}

};

void FPSPlayer::LateUpdate()
{
    VCam.transform.position = transform.position + (Vec3(0.0f, 1.0f, 0.0f) * cameraYOffset);
};

void FPSPlayer::DrawUI()
{
    
};

VirtualCamera FPSPlayer::GetVCam()
{
    return VCam;
};

Transform FPSPlayer::GetVCamTransform()
{
    return VCam.transform;
};


FPSPlayer::FPSPlayer() : Actor()
{
    active = true;
};

FPSPlayer::~FPSPlayer()
{

};

#pragma endregion FPSPlayer


#pragma region TPSPlayer
void TPSPlayer::Update()
{
    Controller& controller = Controller::GetController();

    if(controller.ButtonState(Input_Cross) == held)
    { 
        cameraHolder.transform.rotation += Vec3(0.5f, 0.0f, 0.0f);
        if(cameraHolder.transform.rotation.x > 60.0f)
        {
            cameraHolder.transform.rotation.x = 60.0f;
        }
    }
    if(controller.ButtonState(Input_Triangle) == held)
    { 
        cameraHolder.transform.rotation += Vec3(-0.5f, 0.0f, 0.0f);
        if(cameraHolder.transform.rotation.x < -60.0f)
        {
            cameraHolder.transform.rotation.x = -60.0f;
        }
    }
    if(controller.ButtonState(Input_Square) == held)
    { 
        cameraHolder.transform.rotation += Vec3(0.0f, -1.5f, 0.0f);
    }
    if(controller.ButtonState(Input_Circle) == held)
    { 
        cameraHolder.transform.rotation += Vec3(0.0f, 1.5f, 0.0f);
    }
    Vector2 stick = controller.StickState();
    if(stick == Vector2Zero){ moving = false; }else{ moving = true; }
    if(controller.ButtonState(Input_L) == held){ zooming = true; }else{ zooming = false; }
    if(controller.ButtonState(Input_Down) == press){ crouching = !crouching; }
    if(controller.ButtonState(Input_Up) == press){ switch_shoulder = !switch_shoulder; }

    Vec3 f = (Cross(VCam.transform.RightVec(), Vector3Up));
    Vec3 r = (Cross(VCam.transform.ForwardVec(), Vector3Up));
    Vec3 moveVector = (f * stick.y) + (r * stick.x);

    moveVector.Normalize();
    movementLerper = LerpVec3(movementLerper, moveVector * movementSpeed, 10.0f * DeltaTime());
    transform.position += movementLerper * DeltaTime();

    if(zooming){ FOV = LerpFloat(FOV, zoomFOV, 4 * DeltaTime()); }else{ FOV = LerpFloat(FOV, normalFOV, 4 * DeltaTime()); }
    VCam.FOV = FOV;

    if(crouching){ cameraYOffset = LerpFloat(cameraYOffset, cameraYOffsetCrouch, 4 * DeltaTime());}else{ cameraYOffset = LerpFloat(cameraYOffset, cameraYOffsetNormal, 4 * DeltaTime());}
    if(!switch_shoulder){ shoulder = LerpFloat(shoulder, r_shoulder, 4 * DeltaTime());}else{ shoulder = LerpFloat(shoulder, l_shoulder, 4 * DeltaTime());}

    cameraHolder.transform.position = transform.position + (transform.UpVec() * cameraYOffset);
};

void TPSPlayer::LateUpdate()
{
    VCam.transform.position = (cameraHolder.transform.position) + (cameraHolder.transform.ForwardVec() * -2.0f) + (cameraHolder.transform.RightVec() * shoulder);
    VCam.transform.LookAt(cameraHolder.transform.position + (cameraHolder.transform.ForwardVec() * 10.0f));
};

void TPSPlayer::DrawUI()
{
    
};

void TPSPlayer::DrawModel()
{
    
};

VirtualCamera TPSPlayer::GetVCam()
{
    return VCam;
};

Transform TPSPlayer::GetVCamTransform()
{
    return VCam.transform;
};


TPSPlayer::TPSPlayer() : Actor()
{
    active = true;
    transform.position = Vector3Zero;

    VCam.transform.position = Vector3Zero;
    VCam.transform.rotation = Vec3(10.0f, 0.0f, 0.0f);
};

TPSPlayer::~TPSPlayer()
{
    
};

#pragma endregion TPSPlayer