
#include <LiquidCrystal.h>
#include <DHT.h>

LiquidCrystal lcd(7,6,5,4,2,1); //Creamos el objeto lcd con R/W a GND

int SENSOR = 3;
int humedad, temperatura;

DHT dht(SENSOR, DHT11); //Inicializamos el sensor DHT11

int rgbRojo =10 ;
int rgbVerde = 11;
int rgbAzul = 9;

void setup() {
  // put your setup code here, to run once:

  lcd.begin(16,2); //Inicializar el lcd 16x2
  
  dht.begin(); //Iniciamos el sensor DHT

  pinMode(rgbRojo,OUTPUT);
  pinMode(rgbVerde,OUTPUT);
  pinMode(rgbAzul,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  float temperatura = dht.readTemperature();
  float humedad = dht.readHumidity();

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temperatura);
  lcd.print(" C");

  lcd.setCursor(0,1);
  lcd.print("Hum: ");
  lcd.print(humedad);
  lcd.print(" %");

  delay(3000);

if (temperatura > 25.00) { //color rojo 
  digitalWrite(rgbRojo, 255);
  digitalWrite(rgbVerde, 0);
  digitalWrite(rgbAzul, 0);
}
else if (temperatura >= 20.00) { //color amarillo
  digitalWrite(rgbRojo, 255);
  digitalWrite(rgbVerde, 255);
  digitalWrite(rgbAzul, 0);
}
else { //color verde
  digitalWrite(rgbRojo, 0);
  digitalWrite(rgbVerde, 255);
  digitalWrite(rgbAzul, 0);
}


}
