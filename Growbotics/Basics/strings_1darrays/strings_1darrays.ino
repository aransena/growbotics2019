// Aran Sena 2019

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  String hello_string = "Hello";
  char hello_char_array[] = "Hello";
  
  Serial.println(hello_string);
  Serial.println(hello_char_array);
  
  for(int i = 0; i < sizeof(hello_char_array)-1; i++){
    Serial.println(hello_char_array[i]);
  }
  for(int i = sizeof(hello_string)-2; i >= 0; i--){
    Serial.println(hello_string[i]);
  }
}

void loop() {
}
