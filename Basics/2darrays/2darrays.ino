// Aran Sena 2019

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int xo[3][3] = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};

  Serial.println(xo[1][1]);
  Serial.println(xo[2][1]);
}

void loop() {
}
