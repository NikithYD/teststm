#include "stm32f4xx_hal.h"

void configure_Button();
int main(){

	GPIO_InitTypeDef GPIOD_Params; // Initilisation structure for GPIOD Settings

	uint32_t i; // Loop variable

	__HAL_RCC_GPIOD_CLK_ENABLE(); // Turn on Clock of GPIOD
	configure_Button();
	GPIO_PinState button;
	button = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	// Configure the GPIO Pins 12, 13, 14 and 15 used for LEDs
	GPIOD_Params.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15; // Select pins 12 to 15
	GPIOD_Params.Mode = GPIO_MODE_OUTPUT_PP; // Set pins to push pull output mode
	GPIOD_Params.Speed = GPIO_SPEED_LOW; // Set low output speed
	HAL_GPIO_Init(GPIOD, &GPIOD_Params); // Initialise GPIOD according to parameters on GPIOD_Params
	//last_button_state = GPIOA->IDR & 0x00000001;

	while(1){
        if(button)
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 , GPIO_PIN_SET); // Turn on LEDs
		for(i = 0; i < 200000000; i++){};
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 , GPIO_PIN_RESET); // Turn off LEDs
		for(i = 0; i < 200000000; i++){};

		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13 , GPIO_PIN_SET);
		for(i = 0; i < 200000000; i++){}
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
		for(i = 0; i < 200000000; i++){}

		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14 , GPIO_PIN_SET);
		for(i = 0; i < 200000000; i++){}
	    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
		for(i = 0; i < 200000000; i++){}
	}
}

void configure_Button(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE(); //Enable clock to GPIOA
	GPIO_InitTypeDef PushButton;  // declare a variable of type struct GPIO_InitTypeDef
	PushButton.Mode = GPIO_MODE_INPUT; // set pin mode to input
	PushButton.Pin = GPIO_PIN_0;  // select pin PA0 only
	PushButton.Pull = GPIO_NOPULL; // set no internal pull-up or pull-down resistor
	HAL_GPIO_Init(GPIOA, &PushButton); //  initialize PA0 pins by passing port name and address of PushButton struct
}

