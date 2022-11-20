/*
 * mcal_adc_cfg.h
 *
 *  Created on: May 8, 2020
 *      Author: Andrei Bragarenco
 */

#ifndef _MCAL_ADC_CFG_H_
#define _MCAL_ADC_CFG_H_

#include "./PLF/platform_config.h"

#ifndef MCAL_ADC_CONFIG
#define MCAL_ADC_CONFIG
//for demo application purpose
//shall be defined in the platform
enum MCAL_ADC_Cnl_IdType {ADC_1,ADC_2, ADC_3, MCAL_ADC_CHANNEL_NR_OF};
#endif

enum MCU_ADC_PIN_Cnl_IdType {MCU_ADC_PIN_CHANNEL_NR_OF = MCAL_ADC_CHANNEL_NR_OF};

#endif /* _MCAL_ADC_CFG_H_ */
