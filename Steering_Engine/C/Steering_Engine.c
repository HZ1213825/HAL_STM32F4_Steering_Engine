#include "Steering_Engine.h"
uint16_t Steering_Engine_Count = 0;
uint16_t Steering_Engine_Num = 0;
// R_L为0正转，1逆转 Speed取值范围0-50 越大越快
void Steering_Engine_360(uint8_t R_L, uint8_t Speed)
{
    if (Speed >= 50)
        Speed = 49;
    if (R_L == 0)
    {
        Steering_Engine_Num = 75 - Speed;
    }
    else if (R_L == 1)
    {
        Steering_Engine_Num = 77 + Speed;
    }
}
//输入旋转到的角度,以舵机轴可以面向自己的面为90°，面向左为0°
void Steering_Engine_180(uint8_t Angle)
{
    if (Angle >= 180)
        Angle = 180;
    Steering_Engine_Num = 25 + ((float)Angle / 180 * 100);
}
//定时器中断调用
void Steering_Engine_Action(void)
{
    Steering_Engine_Count++;
    if (Steering_Engine_Count < Steering_Engine_Num)
        HAL_GPIO_WritePin(Steering_Engine_GPIOx, Steering_Engine_GPIO_Pin, GPIO_PIN_SET);
    else
        HAL_GPIO_WritePin(Steering_Engine_GPIOx, Steering_Engine_GPIO_Pin, GPIO_PIN_RESET);
    if (Steering_Engine_Count >= 1000)
        Steering_Engine_Count = 0;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim == &Steering_Engine_TIM)
    {
        Steering_Engine_Action();
    }
}
