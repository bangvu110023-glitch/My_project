#include "DHT.h"

#define DHTPIN 4       // GPIO nối DATA của DHT11
#define DHTTYPE DHT11  // Loại cảm biến

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("Bat dau doc DHT11...");
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Loi khi doc DHT11!");
  } else {
    Serial.print("Nhiet do: ");
    Serial.print(t);
    Serial.println(" *C");

    Serial.print("Do am: ");
    Serial.print(h);
    Serial.println(" %");
  }

  delay(2000); // đọc lại sau 2 giây
}
