static int EnA = 11; // PWM
static int In1 = 10;
static int In2 = 9;

static int In3 = 8;
static int In4 = 7;
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

void setup() {
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

int i = 0;
// Starting from zero, we increase speed 
// until we reach max 255
void loop() {
  // put your main code here, to run repeatedly:
  
  forward(i);
  i = i+10;
  i = min(255,i); 
  delay(50 );
}
