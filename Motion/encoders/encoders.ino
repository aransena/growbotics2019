// Aran Sena April 2019
const int update_interval = 100;

int motor1_raw = 0;
int motor1_prev = 0;
long motor1_ticks = 0;
long motor1_ticks_prev = 0;
unsigned long motor1_time_prev = millis();
unsigned long motor1_time = millis();
int motor1_update_i = 0;
float motor1_speed = 0;
int motor1_dir = 0; // 0 - forward, 1 - backward
const int motor1_ldr = A0;

int motor2_raw = 0;
int motor2_prev = 0;
long motor2_ticks = 0;
long motor2_ticks_prev = 0;
unsigned long motor2_time_prev = millis();
int motor2_dir = 0; // 0 - forward, 1 - backward
const int motor2_ldr = A1;

// A0 Right Wheel
// A1 Left Wheel

void encoderSetup()
{
  pinMode(motor1_ldr, INPUT);
  pinMode(motor2_ldr, INPUT);
  
  motor1_raw = 0;
  motor1_prev = 0;
  motor1_ticks = 0;
  motor1_ticks_prev = 0;
  motor1_dir = 0; // 0 - forward, 1 - backward
  
  motor2_raw = 0;
  motor2_prev = 0;
  motor2_ticks = 0;
  motor2_ticks_prev = 0;
}

void set_encoder_direction(int motor, int motor_dir){
  if(motor == 1){
    motor1_dir = motor_dir;
  }
  else{
    motor2_dir = motor_dir;
  }
}

long update_ticks(int motor_ldr,long motor_ticks, int motor_prev, int motor_dir){
  int motor_raw = analogRead(motor_ldr);
  int motor_state = 0;
  if(motor_raw > 930){
    motor_state = 1;
  }else if(motor_raw < 890){
    motor_state = 0;
  }
  else{
    motor_state = motor_prev;
  }
  if(motor_prev != motor_state){
    motor_prev = motor_state;
    if(motor_dir == 0){ // If forward
      motor_ticks++;
    }
    else{
      motor_ticks--;
    }
  }
  return motor_ticks;
}

long tick_start = 0;
unsigned long time_start = 0;
float get_motor1_speed(){
  Serial.print(String(motor1_update_i) + "\t");
  if(motor1_update_i == 0){
    tick_start = get_motor1_ticks();
    time_start = millis();
    motor1_update_i++;
  }
  else if(motor1_update_i < update_interval){
    motor1_update_i++;
    return motor1_speed;
  }else{
    long delD = get_motor1_ticks() - tick_start;
    unsigned delT = millis() - time_start;
//    float delT = (float) (millis() - motor1_time);
//    long tempTicks = motor1_ticks;
//    motor1_ticks = get_motor1_ticks();
//    long delD = (tempTicks - motor1_ticks);
//    Serial.print(String(delD) + "\t");
    motor1_speed = float(delD/delT);
    motor1_update_i = 0;
    return motor1_speed;
  }
}

long get_motor1_ticks(){
  long tick_update = update_ticks(motor1_ldr, motor1_ticks, motor1_prev, motor1_dir);
  if(tick_update != motor1_ticks){
    motor1_ticks_prev = motor1_ticks;
    motor1_ticks = tick_update;
    motor1_prev = !motor1_prev;
    motor1_time_prev = motor1_time;
    motor1_time = millis();
  }
  return motor1_ticks;
}

long get_motor2_ticks(){
  long tick_update = update_ticks(motor2_ldr, motor2_ticks, motor2_prev, motor2_dir);
  if(tick_update != motor2_ticks){
    motor2_ticks_prev = motor2_ticks;
    motor2_ticks = tick_update;
    motor2_prev = !motor2_prev;
  }
  return motor2_ticks;
}

//int i = 0;
//void loop() {
//  m1_ticks = update_ticks(ldr1, m1_ticks, prev_m1_e, m1_dir);
////  msg = String(m1_ticks);
////  Serial.println(msg);
//  if(m1_ticks != m1_ticks_prev){
//    m1_ticks_prev = m1_ticks;
//    prev_m1_e = !prev_m1_e;
//  }
//  delay(5);
//}
