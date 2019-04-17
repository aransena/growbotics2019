// Aran Sena April 2019

int timesTwo(int x){
  return x * 2;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello from the Arduino!");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    int a = Serial.parseInt(); // Handles combining bytes for us
    int b = timesTwo(a); 
    Serial.println(b);
  }
}
