#pragma once

#include "gameObject.hpp"
#include "inputUtils.hpp"
#include "cameraUtils.hpp"
#include "spriteUtils.hpp"
#include "meshUtils.hpp"
#include "vectorUtils.hpp"
#include "testModel.hpp"
#include "TempModel.hpp"
#include "textureUtils.hpp"

class FPSPlayer : public Actor
{
    bool crouching;
    float cameraYOffset = 1.0f;
    float cameraYOffsetNormal = 1.0f;
    float cameraYOffsetCrouch = 0.35f;
    float movementSpeed = 1.0f;
    bool moving;
    
    bool zooming;
    float FOV;
    float normalFOV = 75.0f;
    float zoomFOV = 45.0f;

    public:
    void Update() override;
    void LateUpdate() override;
    void DrawUI();
    VirtualCamera GetVCam();
    VirtualCamera VCam;
    
    Transform GetVCamTransform();

    FPSPlayer();
    ~FPSPlayer();
};

class TPSPlayer : public Actor
{
    bool crouching = false;
    float cameraYOffset = 1.5f;
    float cameraYOffsetNormal = 1.5f;
    float cameraYOffsetCrouch = 0.75f;
    float movementSpeed = 2.0f;
    bool switch_shoulder = false;
    float shoulder = 1.0f;
    float r_shoulder = 1.0f;
    float l_shoulder = -1.0f;
    float mid_shoulder = 0.0f;
    bool moving;
    
    bool zooming;
    float FOV = 75.0f;
    float normalFOV = 75.0f;
    float zoomFOV = 45.0f;

    public:
    void Update() override;
    void LateUpdate() override;
    void DrawUI();
    void DrawModel();
    VirtualCamera GetVCam();
    VirtualCamera VCam;
    
    GameObject cameraHolder;
    Transform GetVCamTransform();
    C_Texture* tex;

    TPSPlayer();
    ~TPSPlayer();
};