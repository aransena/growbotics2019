// Aran Sena 2019

void setup() {
  Serial.begin(9600);
}

void loop() {
  // If/Else
  if(Serial.available()){
    int iters = Serial.parseInt();
    // For Loop
    for(int i = 0; i < iters; i++){
      Serial.println(i);
      delay(100); // Short delay to help see output
    }
    // While loops
    while(iters >= 0){
      Serial.println(iters);
      delay(100);
      iters--;
    }
  }
  else{
    Serial.println("Waiting...");
    delay(1000);
  }
}
