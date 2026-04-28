#include <SPI.h>
#include <SD.h>

#define CS_PIN 4

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("Iniciando SPI...");
  SPI.begin();
  
  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);
  
  Serial.println("Tentando SD...");
  for (int tentativa = 1; tentativa <= 5; tentativa++) {
    Serial.printf("Tentativa %d...\n", tentativa);
    if (SD.begin(CS_PIN, SPI, 4000000)) {
      Serial.println("SD encontrado!");
      Serial.printf("Tamanho: %llu MB\n", SD.cardSize() / (1024 * 1024));
      return;
    }
    delay(1000);
  }
  Serial.println("SD não respondeu em 5 tentativas.");
}

void loop() {}