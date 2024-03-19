// Deklarera pekare till registren för Port B, Port D och Port B's indataregister
volatile uint8_t* ddrb = (volatile uint8_t*)0x24;
volatile uint8_t* portb = (volatile uint8_t*)0x25;
volatile uint8_t* pinb = (volatile uint8_t*)0x23;

volatile uint8_t* ddrd = (volatile uint8_t*)0x2A;
volatile uint8_t* portd = (volatile uint8_t*)0x2B;
volatile uint8_t* pind = (volatile uint8_t*)0x29;
 
// Variabel för att räkna knapptryckningar
int counter = 0;

void setup() {
  // Ställ in pin 0, 1, 2, 4 och 5 på Port B som utgångar
  *ddrb |= (1 << 0);
  *ddrb |= (1 << 1);
  *ddrb |= (1 << 2);
  *ddrb |= (1 << 4);
  *ddrb |= (1 << 5);

  // Ställ in pin 4, 5, 6 och 7 på Port D som ingångar med pull-up motstånd aktiverade
  *ddrd &= ~(1 << 4);
  *portd |= (1 << 4);

  *ddrd &= ~(1 << 5);
  *portd |= (1 << 5);

  *ddrd &= ~(1 << 6);
  *portd |= (1 << 6);

  *ddrd &= ~(1 << 7);
  *portd |= (1 << 7);

  // Starta seriell kommunikation med baud rate 9600
  Serial.begin(9600);
}

void loop() {
  // Fördröjning för att undvika snabba knapptryckningar
  delay(150);

  // Variabel för att räkna knapptryckningar
  int button_presses = 0;

  // Kontrollera om knappen på pinne 4 på Port D trycks ner
  if (!(*pind & (1 << 4))) {
    *portb |= (1 << 5); // Sätt på blå LED
    counter++; // Öka räknaren
    Serial.println(counter); // Skriv ut räknaren via seriell kommunikation
    button_presses++; // Öka antalet knapptryckningar
  } else {
    *portb &= ~(1 << 5); // Stäng av blå LED
  }

  // Upprepa samma process för de andra knapparna och motsvarande LED-lampor

  // Aktivera andra gröna LED om räknaren är en multipel av 10 och inte noll
  if (counter % 10 == 0 && counter != 0) {
    *portb |= (1 << 0); // Sätt på andra gröna LED
    delay(3000); // Vänta i 3 sekunder
    *portb &= ~(1 << 0); // Stäng av andra gröna LED
  }

  // Aktivera andra gröna LED om minst 2 knappar trycks samtidigt
  if (button_presses >= 2) {
    *portb |= (1 << 0); // Sätt på andra gröna LED
    delay(3000); // Vänta i 3 sekunder
    *portb &= ~(1 << 0); // Stäng av andra gröna LED
  }

  // Återställ räknaren om den når 10 eller mer
  if (counter >= 10) {
    counter = 0; // Återställ räknaren till noll
  }
}