static int m1_s = 5;
static int m1_1 = 8;
static int m1_2 = 9;

static int m2_1 = 10;
static int m2_2 = 11;
static int m2_s = 6;

void backward(){
  digitalWrite(m1_1, LOW);
  digitalWrite(m1_2, HIGH);
  
  digitalWrite(m2_1, LOW);
  digitalWrite(m2_2, HIGH);
}

void forward(){
  digitalWrite(m1_1, HIGH);
  digitalWrite(m1_2, LOW);

  digitalWrite(m2_1, HIGH);
  digitalWrite(m2_2, LOW);
}

void backward(int speed){
  analogWrite(m1_s, speed);
  digitalWrite(m1_1, LOW);
  digitalWrite(m1_2, HIGH);
  
  analogWrite(m2_s, speed);
  digitalWrite(m2_1, LOW);
  digitalWrite(m2_2, HIGH);
}

void forward(int speed){
  analogWrite(m1_s, speed);
  digitalWrite(m1_1, HIGH);
  digitalWrite(m1_2, LOW);

  analogWrite(m2_s, speed);
  digitalWrite(m2_1, HIGH);
  digitalWrite(m2_2, LOW);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(m1_1, OUTPUT);
  pinMode(m1_2, OUTPUT);
  pinMode(m2_1, OUTPUT);
  pinMode(m2_2, OUTPUT);
  pinMode(m1_s, OUTPUT);
  pinMode(m2_s, OUTPUT);
  
  digitalWrite(m1_1, LOW);
  digitalWrite(m1_2, LOW);

  digitalWrite(m2_1, LOW);
  digitalWrite(m2_2, LOW);

}

int i = 0;

void loop() {
  // put your main code here, to run repeatedly:
//  forward();
  forward(i);
//  analogWrite(m1_s, i);
//  analogWrite(m2_s, i);
  i = i+10;
  i = min(255,i);
  delay(50 );
  //backward();
  //delay(500);

}
