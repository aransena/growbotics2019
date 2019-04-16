// Aran Sena April 2019

void setup()
{
  pinMode(11, OUTPUT); // Declare pin type
  pinMode(12, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

int light_val = 0;
int moisture_val = 0;
float temp_val = 0;
float temperature = 0.0;
int i = 0;
bool pump_state = false;
const float tc = 19.53;
String msg;
void loop(){
  digitalWrite(12, pump_state);
  pump_state = !pump_state; // Switch LED State
  
  light_val = analogRead(A0);
  moisture_val = analogRead(A2);
  temp_val = analogRead(A1) * (4976.30 / 1023);
  temperature = (temp_val - 400) /  tc;
  
  // analogRead (0-1024)
  //analogWrite (0-255) -> Have to divide by 4
  
  msg = String(temperature);
  msg = msg + '\t';
  msg = msg + String(light_val);
  msg = msg + '\t';
  msg = msg + String(moisture_val);
  msg = msg + '\t';
  msg = msg + String(pump_state);
  Serial.println(msg);
//  Serial.println(light_val);
  
  analogWrite(11, 255-(light_val / 4)); 
  
  delay(200); // Wait for 200 millisecond(s)
  
}
