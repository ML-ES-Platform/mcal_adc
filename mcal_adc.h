/*
 * mcal_adc.h
 *
 *  Created on: May 8, 2020
 *      Author: Andrei Bragarenco
 */

#ifndef _MCAL_ADC_H_
#define _MCAL_ADC_H_

#include "mcal_adc_cfg.h"


#ifndef MCAL_ADC_CONFIG
enum MCAL_ADC_IdType { MCAL_ADC_CHANNEL_NR_OF = 0};
#endif


typedef struct ADC_ChannelType_t{
	uint8_t adc_pin;
}  ADC_ChannelType;

Std_ReturnType MCAL_ADC_ChannelSetup(Std_ChannelIdType channelId, Std_ChannelIdType adc_pin);
Std_ReturnType ADC_GroupSetup(Std_ChannelIdType *srcIds, Std_ChannelIdType *targhetIds, uint8_t nr_of_channels);


ADC_ChannelType * ADC_GetChannelRef(Std_ChannelIdType channelId);

Std_RawDataType ADC_ReadChannelByRef( ADC_ChannelType * channelRef);

Std_RawDataType ADC_ReadChannel( Std_ChannelIdType channelId);

#endif /* _MCAL_ADC_H_ */
