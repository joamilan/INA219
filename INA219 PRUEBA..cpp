#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

void setup() {
  Serial.begin(9600);
  Serial.println("Measuring voltage and current with INA219...");

  Wire.begin(4, 5);  // Inicializa el bus I2C en los pines GPIO 4 (SDA) y 5 (SCL)

  if (!ina219.begin()) {
    Serial.println("Failed to find INA219 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  float shuntVoltage = ina219.getShuntVoltage_mV(); //Igualo a las variables las funciones
  float busVoltage = ina219.getBusVoltage_V();
  float current_mA = ina219.getCurrent_mA();
  float power_mW = ina219.getPower_mW();

  Serial.print("Shunt Voltage: ");// muestro por el puerto serie
  Serial.print(shuntVoltage);
  Serial.print(" mV, Bus Voltage: ");
  Serial.print(busVoltage);
  Serial.print(" V, Current: ");
  Serial.print(current_mA);
  Serial.print(" mA, Power: ");
  Serial.print(power_mW);
  Serial.println(" mW");

  delay(1000); // Espera 1 segundo entre las lecturas
}
