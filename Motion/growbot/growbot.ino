long m1_ticks = 0;
long m2_ticks = 0;
String msg;
void setup() {
  // put your setup code here, to run once:
  encoderSetup();
  Serial.begin(9600);
  set_encoder_direction(0, 0);
  set_encoder_direction(1, 0);
  sensorSetup();
  motorSetup();
}

int rightState = 0;
int frontState = 0;
int leftState = 0;
int topState = 0;

void loop() {
  // put your main code here, to run repeatedly:
  //  if(topState != 1){
  if (getUltrasonic() >= 15) {
    m1_ticks = get_motor1_ticks();
    m2_ticks = get_motor2_ticks();
    //    rightState = getSensorState(0, 800);
    //    frontState = getSensorState(1, 800);
    //    leftState = getSensorState(2, 800);
    //    topState = getSensorState(3, 600);

    rightState = getSensor(0);
    frontState = getSensor(1);
    leftState = getSensor(2);
    topState = getSensor(3);

    int readings[4] = {rightState, frontState, leftState, topState};
    int k = 0;
    int max_val = readings[k];

    for (int i = 0; i < 4; ++i)
    {
      if (readings[i] > max_val)
      {
        max_val = (int)readings[i];
        k = i;
      }
    }

    if (k == 0) {
      forward(2, 200);
    }
    else if (k == 1) {
      forward(0, 200);
    }
    else if (k == 2) {
      forward(1, 200);
    }
    else if (k == 3) {
      stop_motors();
    }
    else {

    }

    //    if(rightState == 1 && frontState){
    //      forward(2,125);
    //    }
    //    else if(rightState == 1){
    //      forward(2,200);
    //    }
    //    else if(leftState && frontState == 1){
    //      forward(1,125);
    //    }
    //    else if(leftState == 1){
    //      forward(1,200);
    //    }
    //    else if(frontState == 1){
    //      forward(0,150);
    //    }else{
    //      forward(random(3), 150);
    //    }
    //  }

    Serial.print(rightState);
    Serial.print("\t");
    Serial.print(frontState);
    Serial.print("\t");
    Serial.print(leftState);
    Serial.print("\t");
    Serial.print(topState);
    Serial.print("\t");
    Serial.println(k);
    //  float m1s = get_motor1_speed();
    //  Serial.print(m1s,5);
    //  Serial.print("\t");
    //  float m2s = get_motor2_speed();
    //  Serial.print(m2s,5);
    //  Serial.print("\t");
    //  Serial.println((m1s - m2s),5);
  }
  else {
    forward(random(1, 2), 200);
    Serial.println("Obstacle detected");
  }
}

