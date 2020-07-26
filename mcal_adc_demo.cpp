/*
 * mcal_adc_demo.cpp
 *
 *  Created on: May 8, 2020
 *      Author: Andrei Bragarenco
 */

#include "mcal_adc_demo.h"
#include "mcal_adc.h"

//The setup function is called once at startup of the sketch
void mcal_adc_demo_setup() {
// Add your initialization code here
	Serial.begin(9600);
	Serial.println("MCU ADC demo !");
	Std_ReturnType error = E_OK;

	error+= MCAL_ADC_ChannelSetup(ADC_1, A3);
	error+= MCAL_ADC_ChannelSetup(ADC_2, A4);
	error+= MCAL_ADC_ChannelSetup(ADC_3, A5);

	Serial.print("mcal adc Configured, Errors: ");
	Serial.println(error);


}

// The loop function is called in an endless loop
void mcal_adc_demo_loop() {
//Add your repeated code here
	for (int i = 0; i < MCAL_ADC_CHANNEL_NR_OF; i++) {

		Std_RawDataType adcVal = ADC_ReadChannel(i);
		Serial.print(" : ");
		Serial.print(adcVal);
	}
	Serial.println();
	delay(100);
}
