#include <Wiegand.h>

#define D0_PIN D2
#define D1_PIN D3
#define BZ_PIN D4
#define LED_PIN D5
#define WG34_PIN D6

Wiegand wiegand(D0_PIN, D1_PIN);

void setup() {
  Serial.begin(115200);
  pinMode(BZ_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  wiegand.begin();
  Serial.println("Wiegand RFID reader started");
}

void loop() {
  wiegand.read();

  if (wiegand.available()) {
    Serial.print("Wiegand ID: ");
    Serial.println(wiegand.getCode());

    // Realiza acciones adicionales según sea necesario
    digitalWrite(BZ_PIN, HIGH); // Enciende el zumbador
    digitalWrite(LED_PIN, HIGH); // Enciende el LED
    delay(500); // Puedes ajustar la duración
    digitalWrite(BZ_PIN, LOW); // Apaga el zumbador
    digitalWrite(LED_PIN, LOW); // Apaga el LED
  }
}

