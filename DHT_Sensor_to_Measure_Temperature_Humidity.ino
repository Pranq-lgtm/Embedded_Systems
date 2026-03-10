#include "DHT.h"
#define DHTPIN 2  // Connect Data Pin here

#define DHTTYPE DHT11  // Replace 'DHT 11' with 'DHT 21' or 'DHT 22' \
                       // depending upon sensor

// Initialize DHT sensor for use with Arduino
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  // sensor works slow
  // it may take 250 milliseconds for one measurement
  delay(2000);

  float h = dht.readHumidity();     // Read Humidity value and store it in 'h'
  float t = dht.readTemperature();  // Read Temperature as Celsius
  float f = dht.readTemperature(true);// Read Temperature as Fahrenheit
  float hi = dht.computeHeatIndex(f, h);// Compute heat index, temp in Fahrenheit!

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t ");
  Serial.print("Heat Index: ");
  Serial.print(hi);
  Serial.println(" *F ");
 }
