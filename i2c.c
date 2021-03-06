/*
 * i2c.c
 *
 * Created: 17-05-2019 12:27:31
 * Author : Kemal Kapetanovic
 * avr atmega328p 
 */ 

#include <avr/io.h>

#define TW_START   0x08
#define TW_REP_START   0x10
#define TW_STATUS
#define TW_MT_SLA_ACK   0x18

void i2c_init(void){
	
	//Make SDA and SCL inputs
	DDRC=0b1110011; //1 = output, 0 = input
	
	//Disable internal pullups - As internal pull ups are calculated to 5V; The accelerometer uses supply voltage of 1.96-3.6V - 5V may damage it; So SDA=1 would be 5V 
	PORTC=0b1110011
	
	TWCR=(1<<TWEN); // Enable I2C(TWI)
}


/*************************** Generate a Start Condition ***************************/

uint8_t i2c_start_condition(void){     // uint8_t values form 0-255
	
	TWCR=(1<<TWINT | (1<<TWSTA) | (1<<TWEN)) // Send start condition
	                                                             //01010100 =TWCR
	while ((TWCR & (1<<TWINT))==0) // Wait for TWINT to be set     00000100  =1= TWINT 
	{
	}
	
	if ((TWSR & 0xF8) != TW_START)  // 
	{
		printf("i2c_start error\n");
	}
	   else
	
	return (0);
}



/*************************** Generate a repated start condtion ***************************/

uint8_t i2c_repeated_startcondition(void)

{
	TWCR=(1<<TWINT | (1<<TWSTA) | (1<<TWEN)) // Send start condition
	//01010100 =TWCR
	while ((TWCR & (1<<TWINT))==0) // Wait for TWINT to be cleared, TWI will not start until that is done (1 = TWINT cleared)
	{
	}
	
	if ((TWSR & 0xF8) != TW_REP_START)  //
	{
		printf("i2c_start error\n");
	}
	else
	{
		return (0);
	}
}




/*************************** Generate a stop condition ***************************/

uint8_t i2c_stop_condition(void){
	
	TWCR= (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	
	while (TWCR & (1<<TWSTO) == 0) // wait for the stop condition to be set
	{
	}
	
}

/*********************** Function to send slave address ***************************/
uint8_t i2c_sendAddress(uint8_t address)

TWDR = address;

TWCR = (1<< TWINT) | (1<<TWEN);

while (TWCR & (1<<TWINT) == 0) // Wait until TWINT is cleared (writing a 1 to TWINT clears it)
{
}

if ((TWSR & 0xF8) != TW_MT_SLA_ACK)    
{
	printf("SLA+W transmitted, ACK received")
}
else
{
	return(0)
}

/*********************** Function to receive a data byte and send ACKnowledge ***************************/

uint8_t i2c_receiveData_ACK(void){
	
	TWCR =(1<<TWINT) | (1<<TWEA) | (1<<TWEN); //EA enable ack
	
	while (TWCR & (1<<TWINT) == 0)
	{
	}
	
	if ((TWSR & 0xF8) != MT_DATA_ACK
	{
		return(1)
	}
	
	else{
		
		return(0) //data transmitted, ACK received

return(TWDR) //Register gets read here


}


/*********************** Function to receive a data byte and send NOT Acnowledge ***************************/


uint8_t i2c_receiveData_NACK(void){
	
	TWCR =(1<<TWINT) | (1<<TWEA) // EA not set, no ack received
	
	while (TWCR & (1<<TWINT) == 0)
	{
	}

	return(TWDR) //Register gets read here

}


