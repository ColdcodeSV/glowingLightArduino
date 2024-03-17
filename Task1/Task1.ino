volatile uint8_t* ddrb  = (volatile uint8_t*)0x24;
volatile uint8_t* portb = (volatile uint8_t*)0x25;
volatile uint8_t* ddrd  = (volatile uint8_t*)0x2A;
volatile uint8_t* portd = (volatile uint8_t*)0x2B;

void setup() {
  // Set pin 13 (PB5) as an output for the built-in LED
  *ddrb |= (1 << 5);
  
  // Set pin 2 (PD2) as an output for controlling LED
  *ddrd |= (1 << 2);
}