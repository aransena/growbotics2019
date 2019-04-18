// Aran Sena April 2019

int m1_e = 0;
int prev_m1_e = 0;
String msg;
long m1_ticks = 0;
long m1_ticks_prev = 0;
int m1_dir = 0; // 0 - forward, 1 - backward
bool updated = false;
int ldr1 = A1; // Or A0

// A0 Right Wheel
// A1 Left Wheel
// A2 Right Side
// A3 Front
// A4 Left Side
// A5 Up
void setup()
{
  motionSetup();
  pinMode(ldr1, INPUT);
  Serial.begin(9600);
  forward(100);
  m1_dir = 0;
}

float update_ticks(int m_pin,long m_tick, int m_prev, int m_dir){
  int m_curr = analogRead(m_pin);
  msg = String(m_curr);
  msg = msg + "\t" + String(m_tick);
  Serial.println(msg);
  if(m_curr > 930){
    m_curr = 1;
  }else if(m_curr < 890){
    m_curr = 0;
  }
  else{
    m_curr = m_prev;
  }
  if(m_prev != m_curr){
    m_prev = m_curr;
    if(m_dir == 0){ // If forward
      m_tick++;
    }
    else{
      m_tick--;
    }
  }
  return m_tick;
}

int i = 0;
void loop() {
  m1_ticks = update_ticks(ldr1, m1_ticks, prev_m1_e, m1_dir);
//  msg = String(m1_ticks);
//  Serial.println(msg);
  if(m1_ticks != m1_ticks_prev){
    m1_ticks_prev = m1_ticks;
    prev_m1_e = !prev_m1_e;
  }
  delay(5);
//  i++;
//  if (i == 1000 ){
//    m1_dir = 1;
//    backward(100);
//  }else if(i==2000){
//    m1_dir = 0;
//    forward(100);
//    i = 0;
//  }
}
