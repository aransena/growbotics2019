const int sensorPins[4] = {A2, A3, A4, A5};
int numSensors = sizeof(sensorPins) / sizeof(sensorPins[0]);

String getSensors(){
//  int right_ldr = analogRead(A2);
//  int front_ldr = analogRead(A3);
//  int left_ldr = analogRead(A4);
//  int top_ldr = analogRead(A5);
  String msg;
  for(int i=0; i < numSensors ; i++){
    msg = msg + "\t" + analogRead(sensorPins[i]);
  }

  return msg;  
}

void sensorSetup() {
  // put your setup code here, to run once:
  for(int i=0; i < numSensors ; i++){
    pinMode(sensorPins[i], INPUT);
  }

}
