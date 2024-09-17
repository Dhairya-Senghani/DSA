
#include <stdio.h>

// define volatege threshold limit
unsigned short voltage_R_threshold = 270; // Replace with equivalent ADC value
unsigned short voltage_Y_threshold = 270;
unsigned short voltage_B_threshold = 270;

unsigned short current_R_threshold = 5; // Replace with equivalent ADC value
unsigned short current_Y_threshold = 5;
unsigned short current_B_threshold = 5;

unsigned short voltage_R;
unsigned short voltage_Y;
unsigned short voltage_B;

unsigned short current_R;
unsigned short current_Y;
unsigned short current_B;

int main()
{
    while (1)
    {
        // Rough logic to start motor
        if (checkVoltage() != 0)
        {
            // Do not start motor
        }
        else
        {
            startMotor();
            Delay(); // Wait forsome time
            if (checkCurrent() != 0)
            {
                stopMotor();
            }
        }
    }

    return 0;
}

uint8_t checkVoltage()
{

    voltage_R = ADC0_Ch0_Read();
    voltage_Y = ADC0_Ch1_Read();
    voltage_B = ADC0_Ch2_Read();

    if (voltage_R > voltage_R_threshold)
    {
        printf("R phase over voltage\n");
        return 1;
    }
    else if (voltage_Y > voltage_Y_threshold)
    {
        printf("Y phase over voltage\n");
        return 2;
    }
    else if (voltage_B > voltage_B_threshold)
    {
        printf("B phase over voltage\n");
        return 3;
    }
    else
    {
        return 0;
    }
}

uint8_t checkCurrent()
{

    current_R = ADC0_Ch3_Read();
    current_Y = ADC0_Ch4_Read();
    current_B = ADC0_Ch5_Read();

    if (current_R > current_R_threshold)
    {
        printf("R phase over current\n");
        return 1;
    }
    else if (current_Y > current_Y_threshold)
    {
        printf("Y phase over current\n");
        return 2;
    }
    else if (current_B > current_B_threshold)
    {
        printf("B phase over current\n");
        return 3;
    }
    else
    {
        return 0;
    }
}