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
float temp_raw = 0;
float temperature = 0.0;

bool pump_state = false;

// Coefficient for converting
// raw temp vals to degrees celsius
const float tc = 19.53;

String msg;

void loop() {
  light_val = analogRead(A0);
  
  temp_raw = analogRead(A1) * (4976.30 / 1023);
  temperature = (temp_raw - 400) /  tc;
  
  moisture_val = analogRead(A2);

  msg = String(temperature);
  msg = msg + '\t';
  msg = msg + String(light_val);
  msg = msg + '\t';
  msg = msg + String(moisture_val);
  msg = msg + '\t';
  msg = msg + String(pump_state);
  Serial.println(msg);

  /*
   * Decision code on when to activate pump goes here.
   * Just toggling for now.
   */
  digitalWrite(12, pump_state);
  pump_state = !pump_state; // Switch LED State
  
  delay(10); // Wait for 10 millisecond(s)

}
