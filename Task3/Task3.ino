volatile uint8_t* ddrb = (volatile uint8_t*)0x24; // Data Direction Register för port B
volatile uint8_t* portb = (volatile uint8_t*)0x25; // Port B register för att kontrollera utgångar
volatile uint8_t* pinb = (volatile uint8_t*)0x23; // PIN B register för att läsa indata

volatile uint8_t* ddrd = (volatile uint8_t*)0x2A; // Data Direction Register för port D
volatile uint8_t* portd = (volatile uint8_t*)0x2B; // Port D register för att kontrollera utgångar
volatile uint8_t* pind = (volatile uint8_t*)0x29; // PIN D register för att läsa indata

void setup() {
  // Sätt utgång för LED-lamporna
  *ddrb |= (1 << 1); // PB1 för den externa lysdioden
  *ddrb |= (1 << 2); // PB2 för lysdioden på port B
  *ddrb |= (1 << 4); // PB3 för lysdioden på port B
  *ddrb |= (1 << 5); // PB5 för lysdioden på port B
  
  // Knappar som ingångar med pull-up resistor
  *ddrd &= ~(1 << 4); // PD4 för knappen till inbyggd lysdiod
  *portd |= (1 << 4); // Aktivera pull-up resistor för knappen på PD4
  
  *ddrd &= ~(1 << 5); // PD5 för knappen till externa lysdioden på port B
  *portd |= (1 << 5); // Aktivera pull-up resistor för knappen på PD5
  
  *ddrd &= ~(1 << 6); // PD6 för knappen till lysdioden på port C
  *portd |= (1 << 6); // Aktivera pull-up resistor för knappen på PD6
  
  *ddrd &= ~(1 << 7); // PD7 för knappen till lysdioden på port D
  *portd |= (1 << 7); // Aktivera pull-up resistor för knappen på PD7
}