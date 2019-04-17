// Aran Sena April 2019

void setup()
{
  Serial.begin(9600);
  Serial.println("Hello World!");
}

void loop() {
  String name = Serial.readString();
  String msg = "Hello ";
  msg = msg + name;
  msg = msg + "!";
  Serial.println(msg);
  
}
