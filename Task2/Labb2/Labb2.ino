volatile uint8_t* ddrb = (volatile uint8_t*)0x24; // Data Direction Register för port B
volatile uint8_t* portb = (volatile uint8_t*)0x25; // Port B register för att kontrollera utgångar

volatile uint8_t* ddrc = (volatile uint8_t*)0x27; // Data Direction Register för port C
volatile uint8_t* portc = (volatile uint8_t*)0x28; // Port C register för att kontrollera utgångar

volatile uint8_t* ddrd = (volatile uint8_t*)0x2A; // Data Direction Register för port D
volatile uint8_t* portd = (volatile uint8_t*)0x2B; // Port D register för att kontrollera utgångar

// Tidsstämplar för när varje lysdiod senast tändes
unsigned long previousTimeBuiltInLed = 0; // För den inbyggda lysdioden
unsigned long previousTimePortB = 0; // För den externa lysdioden på port B (PB4)
unsigned long previousTimePortC = 0; // För lysdioden på port C (PC3)
unsigned long previousTimePortD = 0; // För lysdioden på port D (PD2)

// Intervall för varje lysdiod (i millisekunder)
int intervalBuiltInLed = 800; // Intervall för den inbyggda lysdioden
int intervalPortB = 1000; // Intervall för den externa lysdioden på port B (PB4)
int intervalPortC = 1200; // Intervall för lysdioden på port C (PC3)
int intervalPortD = 1500; // Intervall för lysdioden på port D (PD2)

void setup() {
  // Sätt utgång för varje lysdiod
  *ddrb |= (1 << 4); // PB4 (externa lysdioden)
  *ddrb |= (1 << 5); // PB5 (inbyggd lysdiod)
  *ddrc |= (1 << 3); // PC3
  *ddrd |= (1 << 2); // PD2
}

void loop() {
  unsigned long currentMillis = millis(); // Aktuell tid

  // Kontrollera om det är dags att tända eller släcka den inbyggda lysdioden
  if (currentMillis - previousTimeBuiltInLed >= intervalBuiltInLed) {
    // Tänd eller släck den inbyggda lysdioden
    PORTB ^= (1 << 5); // Toggla PB5 (inbyggda lysdioden)
    // Uppdatera tidsstämpeln för den inbyggda lysdioden
    previousTimeBuiltInLed = currentMillis;
  }

  // Kontrollera om det är dags att tända eller släcka den externa lysdioden på port B (PB4)
  if (currentMillis - previousTimePortB >= intervalPortB) {
    // Tänd eller släck den externa lysdioden på port B (PB4)
    PORTB ^= (1 << 4); // Toggla PB4 (externa lysdioden)
    // Uppdatera tidsstämpeln för den externa lysdioden på port B (PB4)
    previousTimePortB = currentMillis;
  }

  // Kontrollera om det är dags att tända eller släcka lysdioden på port C (PC3)
  if (currentMillis - previousTimePortC >= intervalPortC) {
    // Tänd eller släck lysdioden på port C (PC3)
    PORTC ^= (1 << 3); // Toggla PC3
    // Uppdatera tidsstämpeln för lysdioden på port C (PC3)
    previousTimePortC = currentMillis;
  }

  // Kontrollera om det är dags att tända eller släcka lysdioden på port D (PD2)
  if (currentMillis - previousTimePortD >= intervalPortD) {
    // Tänd eller släck lysdioden på port D (PD2)
    PORTD ^= (1 << 2); // Toggla PD2
    // Uppdatera tidsstämpeln för lysdioden på port D (PD2)
    previousTimePortD = currentMillis;
  }
}
