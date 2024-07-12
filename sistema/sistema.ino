const int sensorPin = A0;
const int relayPin= 13;

const int humedadEncendido = 25;
const int humedadApagado = 100;

void setup(){
  pinMode(sensorPin, INPUT);
  pinMode(relayPin, OUTPUT);

  Serial.begin(9600);
  while (!Serial);
}

void loop(){
  int humedad = analogRead(sensorPin);

  Serial.print("Humedad: ");
  Serial.println(humedad);

  if (humedad > humedadApagado){
    digitalWrite(relayPin, LOW);
  }
  else if (humedad < humedadEncendido){
    digitalWrite(relayPin, HIGH);
  }
  delay(1000);
}
