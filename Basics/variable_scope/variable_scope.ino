// Aran Sena April 2019

int x = 1;

void setup() {
 int y = 2;
 int a = x + y; // Okay!
 int b = y + z; // Not Okay!
}

void loop() {
  int z = 3;
  int c = z + x; // Okay!
  int d = z + y; // Not Okay!
  int e = z + a; // Not Okay!
}
