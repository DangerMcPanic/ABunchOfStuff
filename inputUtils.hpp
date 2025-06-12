#pragma once

#include <pspctrl.h>
#include "vectorUtils.hpp"

//Buttons
#define INPUT_TRIGGER_L (256)
#define INPUT_TRIGGER_R (512)
#define INPUT_TRIANGLE (4096)
#define INPUT_CIRCLE (8192)
#define INPUT_CROSS (16384)
#define INPUT_SQUARE (32768)
#define INPUT_UP (16)
#define INPUT_RIGHT (32)
#define INPUT_DOWN (64)
#define INPUT_LEFT (128)

#define div_255 (0.00392156862)

enum Button_State
{ 
    non_press, 
    released, 
    press, 
    held, 
};

const int button_indices[10]
{
    {INPUT_UP},
    {INPUT_RIGHT},
    {INPUT_DOWN},
    {INPUT_LEFT},
    {INPUT_TRIGGER_L},
    {INPUT_TRIGGER_R},
    {INPUT_TRIANGLE},
    {INPUT_CIRCLE},
    {INPUT_CROSS},
    {INPUT_SQUARE},
};

enum Button_Type
{ 
    Input_Up, 
    Input_Right, 
    Input_Down, 
    Input_Left,
    Input_L,
    Input_R,
    Input_Triangle,
    Input_Circle,
    Input_Cross,
    Input_Square,
};

class Controller
{
    Button_State button_states[10]
    {
        {non_press},
        {non_press},
        {non_press},
        {non_press},
        {non_press},
        {non_press},
        {non_press},
        {non_press},
        {non_press},
        {non_press},
    };

    Vector2 Analog;

    float stickDeadzone = 0.4f;

    void UpdateButton(SceCtrlData ctrlData, int index);

    public:

    void UpdateController(SceCtrlData ctrlData);
    void SetStickDeadZone(float f);

    Button_State ButtonState(Button_Type bt);
    bool IsButtonState(Button_Type bt, Button_State bs);
    Vector2 StickState();

    static Controller& GetController()
    {
        if(!controllerInstance)
        {
            controllerInstance = new Controller();
        }
        return *controllerInstance;
        
        // static Controller controllerINSTANCE;
        // return controllerINSTANCE;
    };

    //Delete copy constructor
    Controller(const Controller&) = delete;
    Controller& operator=(const Controller&) = delete;

    private:
    Controller();
    ~Controller();

    //Static pointer
    static Controller* controllerInstance;
};




