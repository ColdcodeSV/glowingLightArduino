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

void loop() {
  // Toggle pin 2 (PD2) to control the state of PB5 (pin 13)
  *portd ^= (1 << 2); // Toggle PD2
  
  // Read the state of pin 2 (PD2)
  int controlState = (*portd >> 2) & 1;
  
  // Set pin 12 (PB5) based on the state of pin 2 (PD2)
  if (controlState == 1) {
    *portb |= (1 << 5); // Turn on PB5
  } else {
    *portb &= ~(1 << 5); // Turn off PB5
  }
  
  // Generate a random delay between 1 and 10 seconds for controlling LED
  int delayTime = random(1000, 10001); // Random delay between 1 and 10 seconds
  delay(delayTime);
  
  delay(1000); // Wait for a second
}