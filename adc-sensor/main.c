/* -*- c-file-style: "linux"; c-basic-offset: 4; indent-tabs-mode: nil; -*- */

/*
 * Simple test of the ADC API
 */

/**
 * @ingroup tests
 * @{
 *
 * @file
 * @brief       Test for the TinkerKit LDR sensor
 *
 * @author      Cedric Adjih <cedric.adjih@inria.fr>
 *
 * @}
 */

#include <stdio.h>

#include "cpu.h"
#include "board.h"
//#include "xtimer.h"
#include "periph/adc.h"

#if ADC_NUMOF < 1
#error "Board must support at least one ADC"
#endif

#define ADC_DEVICE_NUMBER  ADC_0
#define ADC_CHANNEL_NUMBER 0
#define ADC_RESOLUTION     ADC_RES_12BIT

int main(void)
{
    printf("Testing ADC measurements\n");
    
    adc_init(ADC_DEVICE_NUMBER, ADC_RESOLUTION);
    
    for (;;) {
        int value = adc_sample(ADC_DEVICE_NUMBER, ADC_CHANNEL_NUMBER);
        printf("adc=%d\n", value);
    }
}
