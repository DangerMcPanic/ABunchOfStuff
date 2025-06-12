#include "inputUtils.hpp"

Controller::Controller()
{

};

Controller::~Controller()
{

};

void Controller::UpdateController(SceCtrlData ctrlData)
{
    #pragma region Stick
    // float result_x = (float)(ctrlData.Lx) / 255.0f;
    // float result_y = (float)(ctrlData.Ly) / 255.0f;

    float result_x = (float)(ctrlData.Lx) * div_255;
    float result_y = (float)(ctrlData.Ly) * div_255;

    result_x = (result_x - 0.5f) * 2.0f;
    result_y = (result_y - 0.5f) * 2.0f;

    if((result_x > -stickDeadzone) && (result_x < stickDeadzone)){ result_x = 0.0f; }
    if((result_y > -stickDeadzone) && (result_y < stickDeadzone)){ result_y = 0.0f; }
    
    Analog.x = result_x;
    Analog.y = result_y;
    #pragma endregion

    #pragma region Buttons
    for(int i = 0; i < sizeof(button_states)/sizeof(Button_State); i++)
    {
        //UpdateButton(ctrlData, i);

        if(ctrlData.Buttons & button_indices[i])
        { 
            if(button_states[i] == non_press || button_states[i] == released)
            {
                button_states[i] = press;
            }
            else if(button_states[i] == press)
            {
                button_states[i] = held;
            }
        }else{
            if(button_states[i] == press || button_states[i] == held)
            {
                button_states[i] = released;
            }
            else
            {
                button_states[i] = non_press;
            }
        }

    }
    #pragma endregion
};

Button_State Controller::ButtonState(Button_Type bt)
{
    return button_states[(int)bt];
};

bool Controller::IsButtonState(Button_Type bt, Button_State bs)
{
    return button_states[(int)bt] == bs;
};

Vector2 Controller::StickState()
{
    return Analog;
};