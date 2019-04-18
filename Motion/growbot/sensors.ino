#include <Ultrasonic.h>

const int sensorPins[4] = {A2, A3, A4, A5};
int numSensors = sizeof(sensorPins) / sizeof(sensorPins[0]);
Ultrasonic ultrasonic(3,2); // Trigger, Echo

int getSensor(int i){
    return analogRead(sensorPins[i]); 
}

int getUltrasonic(){
  return ultrasonic.distanceRead();
}

int getSensorState(int i, int threshold){
    if(analogRead(sensorPins[i])>= threshold){
      return 1; 
    }else{
      return 0;
    }
}

void sensorSetup() {
  // put your setup code here, to run once:
  for(int i=0; i < numSensors ; i++){
    pinMode(sensorPins[i], INPUT);
  }

}
