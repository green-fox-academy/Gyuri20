/* Includes ------------------------------------------------------------------*/
#include "led_matrix.h"
#include "stm32f7xx_hal.h"
#include "lcd_log.h"
#include "cmsis_os.h"
#include "stm32f7xx_hal_gpio.h"
#include "stm32f7xx_hal_adc.h"
#include "stm32f7xx_hal_adc_ex.h"
#include "stm32f7xx_hal_conf.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef adc_handle;
ADC_ChannelConfTypeDef adc_ch_conf;
uint16_t ref = 0;

// Each LED state is stored in this 2D array
GPIO_PinState led_matrix_state[LED_MATRIX_ROWS][LED_MATRIX_COLS];

// Mutex definition
osMutexDef(LED_MATRIX_MUTEX_DEF);
// Mutex global variable
osMutexId led_matrix_mutex_id;
// Declare a message queue
osMessageQDef(adc_message_q, 5, uint32_t);
// Declare an ID for the message queue
osMessageQId (adc_message_q_id);

/* Private function prototypes -----------------------------------------------*/
void led_matrix_set(uint8_t row, uint8_t col, uint8_t state);
/* Private functions ---------------------------------------------------------*/
/* Private structs -----------------------------------------------------------*/
typedef struct {
	GPIO_TypeDef *GPIOx;
	uint16_t GPIO_Pin;
}row;

typedef struct {
	GPIO_TypeDef *GPIOx;
	uint16_t GPIO_Pin;
}column;

void adc_init()
{
	adc_handle.State = HAL_ADC_STATE_RESET;
	adc_handle.Instance = ADC3;
	adc_handle.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
	adc_handle.Init.Resolution = ADC_RESOLUTION_12B;
	adc_handle.Init.EOCSelection = ADC_EOC_SEQ_CONV;
	adc_handle.Init.DMAContinuousRequests = DISABLE;
	adc_handle.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	adc_handle.Init.ContinuousConvMode = DISABLE;
	adc_handle.Init.DiscontinuousConvMode = DISABLE;
	adc_handle.Init.ScanConvMode = DISABLE;
	HAL_ADC_Init(&adc_handle);

	adc_ch_conf.Channel = ADC_CHANNEL_0;
	adc_ch_conf.Offset = 0;
	adc_ch_conf.Rank = 1;
	adc_ch_conf.SamplingTime = ADC_SAMPLETIME_480CYCLES;
	HAL_ADC_ConfigChannel(&adc_handle, &adc_ch_conf);
}

void ADC_thread(void const *argument)
{
	GPIO_InitTypeDef GPIO_Init_ADC;
	__HAL_RCC_ADC3_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_Init_ADC.Pin = GPIO_PIN_0;
	GPIO_Init_ADC.Mode = GPIO_MODE_ANALOG;
	GPIO_Init_ADC.Pull =  GPIO_NOPULL;
	GPIO_Init_ADC.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOA, &GPIO_Init_ADC);

	adc_init();

	adc_message_q_id = osMessageCreate(osMessageQ(adc_message_q), NULL);

	while (1) {
		HAL_ADC_Start(&adc_handle);
		HAL_ADC_PollForConversion(&adc_handle, HAL_MAX_DELAY);
		uint_fast16_t adc_measure = HAL_ADC_GetValue(&adc_handle);
		ref = (adc_measure / 41);

		osMessagePut(adc_message_q_id, adc_measure, osWaitForever);
	}

}

void PIN_Init ()
{
	GPIO_InitTypeDef GPIO_InitDef;
	//Init Port B
	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIO_InitDef.Pin = GPIO_PIN_14 | GPIO_PIN_15 |GPIO_PIN_4;
	GPIO_InitDef.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitDef.Pull =  GPIO_NOPULL;
	GPIO_InitDef.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOB, &GPIO_InitDef);

	//Init Port A
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitDef.Pin = GPIO_PIN_8 | GPIO_PIN_15;
	GPIO_InitDef.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitDef.Pull =  GPIO_NOPULL;
	GPIO_InitDef.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOA, &GPIO_InitDef);

	//Init Port C
	__HAL_RCC_GPIOC_CLK_ENABLE();
	GPIO_InitDef.Pin = GPIO_PIN_6;
	GPIO_InitDef.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitDef.Pull =  GPIO_NOPULL;
	GPIO_InitDef.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOC, &GPIO_InitDef);

	//Init Port H
	__HAL_RCC_GPIOH_CLK_ENABLE();
	GPIO_InitDef.Pin = GPIO_PIN_6;
	GPIO_InitDef.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitDef.Pull =  GPIO_NOPULL;
	GPIO_InitDef.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOH, &GPIO_InitDef);

	//Init Port G
	__HAL_RCC_GPIOG_CLK_ENABLE();
	GPIO_InitDef.Pin = GPIO_PIN_6 | GPIO_PIN_7;
	GPIO_InitDef.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitDef.Pull =  GPIO_NOPULL;
	GPIO_InitDef.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOG, &GPIO_InitDef);

	//Init Port I
	__HAL_RCC_GPIOI_CLK_ENABLE();
	GPIO_InitDef.Pin = GPIO_PIN_0 | GPIO_PIN_2 | GPIO_PIN_3;
	GPIO_InitDef.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitDef.Pull =  GPIO_NOPULL;
	GPIO_InitDef.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOI, &GPIO_InitDef);
}
// TODO:
// Write this function!
osStatus status;

void CreateMutex(void)
{
	led_matrix_mutex_id = osMutexCreate(osMutex (LED_MATRIX_MUTEX_DEF));
	if (led_matrix_mutex_id != NULL)  {
		LCD_UsrLog("Mutex object created\n");
	}
}

void WaitMutex (void)
{
	if (led_matrix_mutex_id != NULL)  {
	status  = osMutexWait    (led_matrix_mutex_id, osWaitForever);
		if (status != osOK)  {
			LCD_ErrLog(" The status code is %d\n", status);
			// handle failure code
		}
	}
}

void ReleaseMutex (osMutexId mutex_id)
{
	if (led_matrix_mutex_id != NULL)  {
	status = osMutexRelease(led_matrix_mutex_id);
		if (status != osOK)  {
			LCD_ErrLog(" The status code is %d\n", status);
			// handle failure code
		}
	}
}

void led_matrix_set(uint8_t row, uint8_t col, uint8_t state) {
	// TODO:
	// Wait for the mutex
	WaitMutex();
	// TODO:
	// Change the LED in the selected row and col to the specified state
	// Use the led_matrix_state 2D array variable!
	//GPIO_PinState
	led_matrix_state[row][col] = state;

	// TODO:
	// Release the mutex
	ReleaseMutex(led_matrix_mutex_id);
}
// TODO:
// Write this function!
void led_matrix_update_thread(void const *argument)
{
	// TODO:
	// Initialize the pins as outputs and the led_matrix_state 2D array
	PIN_Init ();

	row LED_row[LED_MATRIX_ROWS] = {
		{GPIOH,  GPIO_PIN_6},
		{GPIOI,  GPIO_PIN_3},
		{GPIOI,  GPIO_PIN_2},
		{GPIOA,  GPIO_PIN_15},
		{GPIOA,  GPIO_PIN_8},
		{GPIOB,  GPIO_PIN_15},
		{GPIOB,  GPIO_PIN_14}
	};

	column LED_column[LED_MATRIX_COLS] = {
		{GPIOC,  GPIO_PIN_6},
		{GPIOG,  GPIO_PIN_6},
		{GPIOB,  GPIO_PIN_4},
		{GPIOG,  GPIO_PIN_7},
		{GPIOI,  GPIO_PIN_0},
	};

	// TODO:
	// Create a mutex
	// Use the LED_MATRIX_MUTEX_DEFmutex_id = osMutexCreate(osMutex (LED_MATRIX_MUTEX_DEF));
	CreateMutex();
	LCD_UsrLog("led_matrix - initialized\n");

	// Infinite loop
	while (1) {
		// TODO:
		// Implement the led matrix updater functionality
		// Step 1:
		// Iterate through every column or row
		for (int i = 0; i < LED_MATRIX_COLS; i++)  {
			// Step 2:
			// Wait for the mutex
			WaitMutex();
			// Step 3:
			// Turn on the column or row
			HAL_GPIO_WritePin(LED_column[i].GPIOx, LED_column[i].GPIO_Pin, GPIO_PIN_SET);
			// Step 4:
			// Turn on the leds in that column or row
			for (int k = 0; k < LED_MATRIX_ROWS; k++) {
				//HAL_GPIO_WritePin(LED_row[k].GPIOx, LED_row[k].GPIO_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_row[k].GPIOx, LED_row[k].GPIO_Pin, !led_matrix_state[k][i]);
			}
			// Step 5:
			// Release the mutex
			ReleaseMutex(led_matrix_mutex_id);
			// Step 6:
			// Delay
			osDelay(ref);
			// Step 7:
			// Turn off the column or row
			HAL_GPIO_WritePin(LED_column[i].GPIOx, LED_column[i].GPIO_Pin, GPIO_PIN_RESET);
		}//for
	}//while

	// Terminating thread
	while (1) {
		LCD_ErrLog("led_matrix - terminating...\n");
		osThreadTerminate(NULL);
	}
}//main

// This thread is a waterfall type animation
void led_matrix_waterfall_thread(void const *argument)
{
	osEvent event;
	while (1) {
		for (uint8_t r = 0; r < LED_MATRIX_ROWS; r++) {
			for (uint8_t c = 0; c < LED_MATRIX_COLS; c++) {
				led_matrix_set(r, c, 1);
				// wait for message
				event = osMessageGet(adc_message_q_id, osWaitForever);
				osDelay(ref);
				led_matrix_set(r, c, 0);
			}
		}
	}

	while (1) {
		LCD_ErrLog("led_matrix_waterfall - terminating...\n");
		osThreadTerminate(NULL);
	}
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
