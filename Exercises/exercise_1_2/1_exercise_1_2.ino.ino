float circumference(float radius){
  return 2 * PI * radius;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(circumference(0.1), 5);
}

void loop() {
  // put your main code here, to run repeatedly:
  float r = Serial.parseFloat();
  Serial.println(circumference(r), 4);
}
