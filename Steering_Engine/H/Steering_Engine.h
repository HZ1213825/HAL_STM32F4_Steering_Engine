#ifndef __STEERING_ENGINE_H
#define __STEERING_ENGINE_H

#include "main.h"
/*
需要
1.开漏浮空输出
    舵机是5V电压，用浮空输出，外接5V上拉方式实现，
    需要在数据手册中带FT的管脚
2.定时器
    需要开启中断
    每隔20us触发一次中断
    不要忘记在定时器初始化函数中调用 HAL_TIM_Base_Start_IT();
*/
extern TIM_HandleTypeDef htim2;

#define Steering_Engine_GPIOx GPIOA
#define Steering_Engine_GPIO_Pin GPIO_PIN_0

#define Steering_Engine_TIM htim2

void Steering_Engine_Action(void);
void Steering_Engine_180(uint8_t Angle);
void Steering_Engine_360(uint8_t R_L, uint8_t Speed);
#endif
