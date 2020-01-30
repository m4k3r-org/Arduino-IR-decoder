// Lathe GUI on ATMega328 - see README.asciidoc

#include <bsp.h>
#include <bsp_platform.h>
#include <lathe_gui.h>
#include <pinmapping.h>
#include <timer1.h>
#include <debug_uart0.h>

// Number of input shift registers
#define NUMBER_SHIFT_IN_BYTES 2

/**
 * Shifted in bits of the input shift registers - handles buttons.
 */
static uint8_t shiftInValues[NUMBER_SHIFT_IN_BYTES];

/**
 * Set all pins to default status and reset all HW the way we use them.
 */
static void resetAllHW();

/**
 * Set up pinpad input ADC to start reading value
 */
static void startPinPadADC()
{
	ADCSRA|=_BV(ADSC);
}
/**
 * Process current time and current measured pressed button index.
 * Debounce the button event and execute button handler when debounced event happens.
 * @param t current time in millis
 * @param pressedIndex the result of current measurement of buttons input
 */
static void debounceAndExecute(uint32_t t, uint8_t pressedIndex)
{
	static uint32_t eventT=0;
	static uint8_t index=-1;
	static uint8_t status=0;
	switch(status)
	{
		case 0:	// idle
			if(pressedIndex!=255)
			{
				index=pressedIndex;
				eventT=t;
				status=1;
			}
			break;
		case 1: // pre-press
			if(pressedIndex==index)
			{
				// Same button - check time
				if(t-eventT>50)
				{
//					UART0_Send('i');
//					UART0_Send_uint32(pressedIndex);
//					UART0_Send('\n');
					gui_buttonPressed(pressedIndex);
					status=2;
				}
			}else
			{
				status=0;
			}
			break;
		case 2: // press handled
			if(pressedIndex==index)
			{
				// Nothing to do
			}else
			{
				// Button unpressed
				status=3;
				eventT=t;
			}
			break;
		case 3: // Unpress started - after a timeout go to idle
			if(t-eventT>50)
			{
				status=0;
			}
			break;
		default:
			status=0;	// Never happens but return to normal states though
			break;
	}
}
/**
 * Wait pinpad input reading and store the input value.
 * @return index of the button pressed in the current moment -1 means none pressed
 */
static int8_t finishPinPadADC()
{
	/// Exit loop when either there is no running ADC or there is an active ready signalling.
	while( ((ADCSRA&_BV(ADIF)) == 0 ) && ((ADCSRA&_BV(ADSC)) == 1))
	{
	}
	int8_t pressedIndex=-1;
	/// If there is a ready signalling...
	if((ADCSRA&_BV(ADIF)) != 0)
	{
		/// Clear ready singalling
		ADCSRA|=_BV(ADIF);
		uint16_t value=ADC;

/// Accept range around exact value
#define RANGE 0.05
#define VOLT_TO_VALUE(X) ((uint16_t)((X)*1024.0/5.14))
#define AROUND(X) value>=VOLT_TO_VALUE((X)-RANGE)&&value<VOLT_TO_VALUE((X)+RANGE)
		// Numbers:
		if(AROUND(1.02)) pressedIndex=1;
		if(AROUND(1.22)) pressedIndex=2;
		if(AROUND(1.46)) pressedIndex=3;
		if(AROUND(1.71)) pressedIndex=4;
		if(AROUND(2.02)) pressedIndex=5;
		if(AROUND(2.42)) pressedIndex=6;
		if(AROUND(2.81)) pressedIndex=7;
		if(AROUND(3.11)) pressedIndex=8;
		if(AROUND(3.31)) pressedIndex=9;
		if(AROUND(3.91)) pressedIndex=0;
		if(AROUND(3.60)) pressedIndex=10;
		if(AROUND(3.77)) pressedIndex=11;
	}
	return pressedIndex;
}
static inline uint8_t max8(uint8_t a, uint8_t b)
{
	return a>b?a:b;
}
static uint8_t getOutputByte(uint8_t i, uint8_t nbytes)
{
	uint8_t hatravan=nbytes-i-1;
	if(hatravan<NUMBER_DISPLAY_ALLBYTES)
	{
		return segmentValues[hatravan];	// We send index 0 last
	}else
	{
		return 0b01010101;	// Do not cate - bacause this will be shifted through all registers
	}
}
static void storeInputByte(uint8_t i, uint8_t nbytes, uint8_t value)
{
	if(i<NUMBER_SHIFT_IN_BYTES)
	{
		shiftInValues[i]=value;
	}// else do not care because those values are garbage input on the last shift register
}
/**
 * Shift in and out into and from the shift registers that handle input/output.
 */
static void shiftButtonsAndSegments()
{
	uint8_t status;
	uint8_t value;
	uint8_t nbytes=max8(NUMBER_DISPLAY_ALLBYTES, NUMBER_SHIFT_IN_BYTES);

	// Strobe on input SHRs reads current button states
	SHIFT_IN_LATCH_ON();
	_delay_us(10);
	SHIFT_IN_LATCH_OFF();

	// Turn SS to output! Otherwise low SS would transition SPI into slave mode!
	SPI_SS_MASTER();
	SPCR=_BV(SPE)
	//	|_BV(DORD) // DORD: LSB is transmitted first
		|_BV(MSTR);
	SPCR|=0b01;	// clockdiv: /16
	SPSR&=~_BV(SPI2X); // Disable clock x2
	status=SPSR; value=SPDR;	// Reset status
	for(int i=0;i<nbytes;++i)
	{
		SPDR=getOutputByte(i, nbytes);
		while((SPSR&_BV(SPIF))==0);	// Wait until transfer is finished
		status=SPSR; value=SPDR;	// Reset status and read value
		storeInputByte(i, nbytes, value);
	}
	SPCR=0;	// disable SPI
	DIGITS_LATCH_ON();	// Strobe on Latch loads value into the output register of shifts
	_delay_us(10);
	DIGITS_LATCH_OFF();
}

// Ugly hack to include the source code but it works :-)
#include "sensor_readout.cpp"
/**
 * Read the values from the quad decoders and update the locally stored value.
 */
static void readQuadDecoders()
{
	sensor_readout(0);
	sensor_readout(1);
}

static uint8_t decodeShiftRegBitIndexToButtonIndex(uint8_t shiftBitIndex)
{
	switch(shiftBitIndex)
	{
		case 0: return 200;
		case 1: return 201;
		case 2: return 202;
		case 3: return 203;
		case 4: return 204;
		case 5: return 205;
		case 6: return 206;
	}
	return 255;
}
/**
 * Decode shift in button to index.
 * @return -1 means no button
 */
static int8_t decodeShiftInButton()
{
	uint8_t currentIndex=255;
	uint8_t nFound=0;
	for(uint8_t byteIndex=0;byteIndex<NUMBER_SHIFT_IN_BYTES;++byteIndex)
	{
		uint8_t mask=0b10000000;
		for(uint8_t bitIndex=0;bitIndex<8;++bitIndex)
		{
			if((shiftInValues[byteIndex]&mask)!=0)
			{
				currentIndex=byteIndex*8+bitIndex;
				nFound++;
			}
			mask>>=1;
		}
	}
	if(nFound!=1)
	{
		currentIndex=255;
	}
	return currentIndex;
}

/**
 * TODO call this on power fail before saving state into EEPROM.
 */
static void disableAllHardware()
{
	// TODO disable all hardware - executed on pre-power fail to spare energy for state saving
	// TODO disable SPI
	// disable ADC
	ADMUX=0;
	ADCSRA=0;
	ADCSRB=0;
	// TODO disable PWM
	// TODO turn pins off
}

int main()
{
	resetAllHW();
	gui_init();
	gui_setup();
	while(1)
	{
		// Single period time: about 16ms - perfect
		uint32_t t=getCurrentTimeMillis();
		startPinPadADC();	// ADC takes time - we do useful stuff while it is running
		shiftButtonsAndSegments();
		readQuadDecoders();
		uint8_t shiftInButton=decodeShiftInButton();
		uint8_t pinPadButton=finishPinPadADC();
		uint8_t b=pinPadButton!=255?pinPadButton:shiftInButton; // Pinpad has higher priority
		debounceAndExecute(t, b);
		gui_loop(t);
	}
}

static void resetAllHW()
{
	// Input/pullup on all pins
	DDRB=0;
	PORTB=0xFF;
	DDRC=0;
	PORTC=0xFF;
	DDRD=0;
	PORTD=0xFF;

	// TODO AIN0 and AIN1 - power fail detector
	DIDR1|=_BV(AIN1D)|_BV(AIN0D);	// Disable digital input on Analog comparator pins

	DIGITS_LATCH_OFF();
	SHIFT_IN_LATCH_OFF();
	PINPAD_INPUT();
	CONFIG_PWM_PINS();

	NCS_SENSOR_OFF(0);
	NCS_SENSOR_OFF(1);

	// AD converter set up:
	ADMUX=_BV(REFS0)|0b0000; // Reference is VCC and input is ADC0
	ADCSRA=_BV(ADEN)|0b111;	// Enabled but no auto. Pre scaler is 128 which means 62.5-125kHz (assuming CPU is 8MHz - 16MHz)
				// ADC takes 13 cycles so we are still over 1kHz with frequency
	ADCSRB=0;
	DIDR0|=_BV(ADC0D);	// Disable digital input on ACD0 pin to spare some power
	initTimer1();
	UART0_Init();	// Debug messages are sent using UART0
	sei();
}

