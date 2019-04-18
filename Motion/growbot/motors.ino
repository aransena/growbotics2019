// Aran Sena April 2019

static int EnA = 11; // PWM
static int In1 = 10;
static int In2 = 9;

static int In3 = 7;
static int In4 = 8;
static int EnB = 6; // PWM

void backward(int speed){
  analogWrite(EnA, speed);
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  
  analogWrite(EnB, speed);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
}

void forward(int speed){
  analogWrite(EnA, speed);
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);

  analogWrite(EnB, speed);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
}

void backward(int side, int speed){
  if(side == 1){
    analogWrite(EnA, speed);
    digitalWrite(In1, LOW);
    digitalWrite(In2, HIGH);
//    analogWrite(EnB, speed);
    digitalWrite(In3, LOW);
    digitalWrite(In4, LOW);
  }else if( side == 2){  
    analogWrite(EnB, speed);
    digitalWrite(In3, LOW);
    digitalWrite(In4, HIGH);
//    analogWrite(EnA, speed);
    digitalWrite(In1, LOW);
    digitalWrite(In2, LOW);
  }else{  
    analogWrite(EnA, speed);
    digitalWrite(In1, LOW);
    digitalWrite(In2, HIGH);
    
    analogWrite(EnB, speed);
    digitalWrite(In3, LOW);
    digitalWrite(In4, HIGH);
  }
}

void forward(int side, int speed){
  if(side == 1){
    analogWrite(EnA, speed);
    digitalWrite(In1, HIGH);
    digitalWrite(In2, LOW);
//    analogWrite(EnB, speed);
    digitalWrite(In3, LOW);
    digitalWrite(In4, LOW);
  }else if( side == 2){  
    analogWrite(EnB, speed);
    digitalWrite(In3, HIGH);
    digitalWrite(In4, LOW);
//    analogWrite(EnA, speed);
    digitalWrite(In1, LOW);
    digitalWrite(In2, LOW);
  }else{  
    analogWrite(EnA, speed);
    digitalWrite(In1, HIGH);
    digitalWrite(In2, LOW);
    
    analogWrite(EnB, speed);
    digitalWrite(In3, HIGH);
    digitalWrite(In4, LOW);
  }
}

void left(int speed){
  if(speed < 0){
    speed = speed * -1;
    backward(0, speed);
  }else{
    forward(0, speed);
  }
}

void right(int speed){
  if(speed < 0){
    speed = speed * -1;
    backward(1, speed);
  }else{
    forward(1, speed);
  }
}

void stop_motors(){
  analogWrite(EnA, 0);
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  
  analogWrite(EnB, 0);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
}

void motorSetup() {
  // put your setup code here, to run once:
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
  
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);

  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);

}
//
//int i = 0;
//// Starting from zero, we increase speed 
//// until we reach max 255
//void loop() {
//  // put your main code here, to run repeatedly:
//  
//  forward(i);
//  i = i+10;
//  i = min(255,i); 
//  delay(50 );
//}
