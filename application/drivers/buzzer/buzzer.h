/**
 ******************************************************************************
 * @author: Nark
 * @date:   17/05/2024
 ******************************************************************************
**/

#ifndef __BUZZER_H__
#define __BUZZER_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "io_cfg.h"

/*-----------------------------------------------------------------*/
/*                        led life pin map                         */ 
/*-----------------------------------------------------------------*/
#define BUZZER_IO_PIN					(GPIO_Pin_0)
#define BUZZER_IO_PORT					(GPIOA)
#define BUZZER_IO_CLOCK					(RCC_AHBPeriph_GPIOA)

#define BUZZER_IO_AF                    (GPIO_AF_TIM2)
#define BUZZER_IO_SOURCE                (GPIO_PinSource0)

#define BUZZER_TIM                      (TIM2)
#define BUZZER_TIM_PERIPH               (RCC_APB1Periph_TIM2)
#define BUZZER_TIM_IRQ                  (TIM2_IRQn)

/* single tone definition */
typedef struct {
	uint16_t frequency;
	uint8_t  duration;
} tone_t;

static const tone_t tone_startup[] = {
	{2000,3},
	{   0,3},
	{3000,3},
	{   0,3},
	{4000,3},
	{   0,3},
	{1200,4},
	{   0,6},
	{4500,6},
	{   0,0}     // <-- tones end
};

static const tone_t tone_1beep[] = {
	{1500, 3}
};

static const tone_t tone_3beep[] = {
	{4000, 3},
	{   0,10},
	{1000, 6},
	{   0,10},
	{4000, 3},
	{   0, 0}
};

// "Super Mario bros." =)
static const tone_t tone_SMB[] = {
	{2637,18}, // E7 x2
	{   0, 9}, // x3
	{2637, 9}, // E7
	{   0, 9}, // x3
	{2093, 9}, // C7
	{2637, 9}, // E7
	{   0, 9}, // x3
	{3136, 9}, // G7
	{   0,27}, // x3
	{1586, 9}, // G6
	{   0,27}, // x3

	{2093, 9}, // C7
	{   0,18}, // x2
	{1586, 9}, // G6
	{   0,18}, // x2
	{1319, 9}, // E6
	{   0,18}, // x2
	{1760, 9}, // A6
	{   0, 9}, // x1
	{1976, 9}, // B6
	{   0, 9}, // x1
	{1865, 9}, // AS6
	{1760, 9}, // A6
	{   0, 9}, // x1

	{1586,12}, // G6
	{2637,12}, // E7
	{3136,12}, // G7
	{3520, 9}, // A7
	{   0, 9}, // x1
	{2794, 9}, // F7
	{3136, 9}, // G7
	{   0, 9}, // x1
	{2637, 9}, // E7
	{   0, 9}, // x1
	{2093, 9}, // C7
	{2349, 9}, // D7
	{1976, 9}, // B6
	{   0,18}, // x2

	{2093, 9}, // C7
	{   0,18}, // x2
	{1586, 9}, // G6
	{   0,18}, // x2
	{1319, 9}, // E6
	{   0,18}, // x2
	{1760, 9}, // A6
	{   0, 9}, // x1
	{1976, 9}, // B6
	{   0, 9}, // x1
	{1865, 9}, // AS6
	{1760, 9}, // A6
	{   0, 9}, // x1

	{1586,12}, // G6
	{2637,12}, // E7
	{3136,12}, // G7
	{3520, 9}, // A7
	{   0, 9}, // x1
	{2794, 9}, // F7
	{3136, 9}, // G7
	{   0, 9}, // x1
	{2637, 9}, // E7
	{   0, 9}, // x1
	{2093, 9}, // C7
	{2349, 9}, // D7
	{1976, 9}, // B6

	{   0, 0}
};

// Merry Christmas
static const tone_t tone_merry_chrismast[] = {
	{2637, 9}, // E7
	{   0, 9}, // x1
	{2637, 9}, // E7
	{   0, 9}, // x1
	{2637, 9}, // E7
	{   0,18}, // x2

	{2637, 9}, // E7
	{   0, 9}, // x1
	{2637, 9}, // E7
	{   0, 9}, // x1
	{2637, 9}, // E7
	{   0,18}, // x2

	{2637, 9}, // E7
	{   0, 9}, // x1
	{3136, 9}, // G7
	{   0, 9}, // x1
	{2093, 9}, // C7
	{   0, 9}, // x1
	{2349, 9}, // D7
	{   0, 9}, // x1
	{2637, 9}, // E7
	{   0,24}, // x2

	{2794, 9}, // F7
	{   0, 9}, // x1
	{2794, 9}, // F7
	{   0, 9}, // x1
	{2794, 9}, // F7
	{   0, 9}, // x1
	{2794, 9}, // F7
	{   0, 9}, // x1
	{2794, 9}, // F7
	{   0, 9}, // x1
	{2637, 9}, // E7
	{   0, 9}, // x1
	{2637, 9}, // E7
	{   0, 9}, // x1
	{2637, 9}, // E7
	{   0, 9}, // x1
	{2637, 9}, // E7
	{   0, 9}, // x1
	{2637, 9}, // E7
	{   0, 9}, // x1
	{2349, 9}, // D7
	{   0, 9}, // x1
	{2349, 9}, // D7
	{   0, 9}, // x1
	{2637, 9}, // E7
	{   0, 9}, // x1
	{2349, 9}, // D7
	{   0, 9}, // x1
	{3136, 9}, // G7
	{   0, 0}  // <-- tones end
};

/* function prototypes */
extern void buzzer_init();
extern void buzzer_enable(uint16_t freq, uint32_t duration);
extern void buzzer_disable();
extern void buzzer_play_tone(const tone_t * melody);

extern void buzzer_irq( void );

#ifdef __cplusplus
}
#endif

#endif // __BUZZER_H__
