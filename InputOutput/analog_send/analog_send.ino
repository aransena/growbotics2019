// Aran Sena April 2019

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

int light_val = 0;
String msg;

void loop() {
  light_val = analogRead(A0);
  msg = String(light_val);
  Serial.println(msg);
  delay(10); // Wait for 10 millisecond(s)

}
