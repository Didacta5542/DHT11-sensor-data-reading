#include <DHT.h>

// Configuración del DHT11
#define DHTPIN 2     // Pin donde está conectado el sensor DHT11
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  dht.begin();
}

void loop() {
  // Esperar 2 segundos entre lecturas
  delay(1000);

  // Leer la humedad y la temperatura del DHT11
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Comprobar si alguna lectura ha fallado
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Enviar datos por el puerto serie
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C, ");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" %");
}