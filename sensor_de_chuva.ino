#define sensorPower 7
#define sensorPin 8
#define humPin A0


void setup() {
  pinMode(sensorPower, OUTPUT);
  pinMode(humPin, INPUT);

  digitalWrite(sensorPower, LOW);
  Serial.begin(9600);
  }
  void loop() {
    int val = readSensor();
    int hum = analogRead(humPin);
    Serial.print("Humidade: ");
    Serial.println(1 -(hum /1024.0));

    Serial.print("SAIDA DIGITAL: ");
    Serial.println(val);

    if(val) {
      Serial.println("Status:  Não está chovendo");
    } else {
      Serial.println("Status: Está chovendo: ");
    }
    delay(1000);
    Serial.println();
    }
    int readSensor() {
      digitalWrite(sensorPower, HIGH);
      delay(10);
      int val = digitalRead(sensorPin);
      digitalWrite(sensorPower, LOW);
      return val;
    }