#define PIR_PIN 14
#define LDR_PIN 34
#define LED_PIN 25
#define RELAY_FAN 26

void setup()
{
  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(RELAY_FAN, OUTPUT);

  // initial states
  digitalWrite(RELAY_FAN, HIGH);   // fan OFF
  digitalWrite(LED_PIN, LOW);      // light OFF

  Serial.println("System Ready");
}

void loop()
{
  int motion = digitalRead(PIR_PIN);
  int lightValue = analogRead(LDR_PIN);

  Serial.print("Motion: ");
  Serial.print(motion);
  Serial.print("  Light: ");
  Serial.println(lightValue);

  // FAN CONTROL
  if (motion == HIGH)
  {
    digitalWrite(RELAY_FAN, LOW);   // fan ON
  }
  else
  {
    digitalWrite(RELAY_FAN, HIGH);  // fan OFF
  }

  // LIGHT CONTROL
  if (motion == HIGH && lightValue > 2500)
  {
    digitalWrite(LED_PIN, HIGH);    // LED ON
  }
  else
  {
    digitalWrite(LED_PIN, LOW);     // LED OFF
  }

  delay(2000);
}
