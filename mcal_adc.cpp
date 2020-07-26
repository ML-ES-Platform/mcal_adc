/*
 * mcal_adc.cpp
 *
 *  Created on: May 8, 2020
 *      Author: Andrei Bragarenco
 */

#include "mcal_adc.h"

#ifdef PLATFORM_CONFIG_ENABLE
extern ADC_ChannelType ADC_Channels[MCAL_ADC_CHANNEL_NR_OF];
#else
ADC_ChannelType ADC_Channels[MCAL_ADC_CHANNEL_NR_OF];
#endif
/**
 * @brief 
 * 
 * @param srcIds 
 * @param targhetIds 
 * @param nr_of_channels 
 * @return Std_ReturnType 
 */
Std_ReturnType ADC_GroupSetup(Std_ChannelIdType *srcIds, Std_ChannelIdType *targhetIds, uint8_t nr_of_channels)
{
	Std_ReturnType error = E_OK;

	for (size_t i = 0; i < nr_of_channels; i++)
	{
		Std_ChannelIdType srcId = srcIds[i];
		Std_ChannelIdType targhetId = targhetIds[i];
		error += MCAL_ADC_ChannelSetup(srcId, targhetId);
	}
	return error;
}
Std_ReturnType MCAL_ADC_ChannelSetup(Std_ChannelIdType channelId, Std_ChannelIdType adc_pin)
{
	Std_ReturnType error;
	if (channelId < MCAL_ADC_CHANNEL_NR_OF)
	{
		ADC_ChannelType *channelRef = ADC_GetChannelRef(channelId);
		channelRef->adc_pin = adc_pin;
		error = E_OK;
	}
	else
	{
		error = E_NOT_OK;
	}
	return error;
}

ADC_ChannelType *ADC_GetChannelRef(Std_ChannelIdType channelId)
{
	ADC_ChannelType *channelRef = &ADC_Channels[channelId];
	return channelRef;
}

Std_RawDataType ADC_ReadChannelByRef(ADC_ChannelType *channelRef)
{
#ifdef ARDUINO
	Std_RawDataType adcValue = analogRead(channelRef->adc_pin);
#elif defined ESP

#endif

	return adcValue;
}

Std_RawDataType ADC_ReadChannel(Std_ChannelIdType channelId)
{
	ADC_ChannelType *channelRef = ADC_GetChannelRef(channelId);
	Std_RawDataType adcValue = ADC_ReadChannelByRef(channelRef);
	return adcValue;
}
