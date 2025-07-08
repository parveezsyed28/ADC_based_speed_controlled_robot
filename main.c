#include<avr/io.h>
#include<util/delay.h>

void init_adc()  //ADC initializing function
{
ADCSRA|=(0b00000001<<ADEN); //Enables the ADC
ADCSRA|=(0b00000001<<ADPS2); //Sets the sampling rate
ADMUX|=(0b00000001<<REFS0); //Reference voltage
}

unsigned int read_adc()
{
int p=0b00000000; //Select the input pin
ADMUX|=p;
ADCSRA|=(0b00000001<<ADSC); //Starting the conversion

while((ADCSRA&(0b00000001<<ADIF))==0){} //Checking for end of conversion
ADCSRA|=0b00000001<<ADIF; //Clear ADIF bit

return (ADC);
}


void delay(int n)
{
for(int i=0;i<n;i++)
{
_delay_ms(1);
}

}


void linefollower(int n)
{

DDRB=0b11111111; //Setting part B as output for motors
DDRC=0b11111111; //Setting part C as ouput for buzzer

if((n&0b00000011)==0b00000000) //Both sensors are on light surface
	PORTB=0b00001010; //Go straight
if((n&0b00000011)==0b00000001) //Right sensor is on dark surface
	PORTB=0b00001001; //Turn right
if((n&0b00000011)==0b00000010) //Left sensor is on dark surface
	PORTB=0b00000110; //Turn left
if((n&0b00000011)==0b00000011) //Both sensors are on dark surface
{
	PORTB=0b00001010; //Go straight
	PORTC=0b00000001; //Beep
}
}

void main()
{
DDRD=0b00000000; //Setting part D as input
DDRB=0b11111111; //Setting part B as output for motor
PORTD=0b11111111; //Pulling up all the pins of D
DDRC=0b11111111; //Setting part C as ouput for buzzer

init_adc(); //Call ADC initializing
_delay_ms(200); //Delay to make sure that ADC is initialized
int c;

while(1)
{
c=PIND;
if((c&0b00000100)==0b00000000) // Obstacle present
{
PORTB=0b00000000; //Stop
PORTC=0b00000001; //Beep
}
else //No obstacle
{
if((c&0b00001000)==0b00000000) //Inside the cave
{
unsigned int a;  //Initialized as unsigned int as it relates to analog input
unsigned int p;
unsigned int T;
unsigned int TON;
unsigned int TOFF;

p=read_adc(); //Read the ADC input from ADC
a=p/40; //Scaling the total time period
T=25; //Total time period
TON=a; //ON time based on the current analog input

TOFF=T-TON; //OFF time=Total time period-ON time

linefollower(c);
delay(TON);
PORTB=0b00000000;
delay(TOFF);
}
else
	linefollower(c);
}
}
}
	
