// Aran Sena April 2019

void setup()
{
  pinMode(11, OUTPUT); // Declare pin type
  pinMode(12, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

int light_val = 0;
int i = 0;
bool led_state = false;

void loop()
{
  digitalWrite(12, led_state);
  led_state = !led_state; // Switch LED State
  
  light_val = analogRead(A0);
  
  // analogRead reads in range (0-1024) but analogWrite 
  // takes values (0-255) -> Have to divide by 4
  Serial.println(light_val);
  analogWrite(11, 255-(light_val / 4)); 
  
  delay(200); // Wait for 200 millisecond(s)
  
}
