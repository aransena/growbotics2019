/**
 * Simple Read
 * 
 * Read data from the serial port and change the color of a rectangle
 * when a switch connected to a Wiring or Arduino board is pressed and released.
 * This example works with the Wiring / Arduino program that follows below.
 */


import processing.serial.*;

Serial myPort;  // Create object from Serial class
String val;      // Data received from the serial port
String raw_vals;
String vals[];
int light;
int light_avg = 0;
int moisture;
int pump;
int[] light_hist;
float temp;
float[] temp_hist;
float temp_avg = 0;
float max_temp = 42.0;
float min_temp = 0.0;

void setup() 
{
  size(800, 600);
  light_hist = new int[width];
  temp_hist = new float[width];
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);

}

void draw()
{ 
  background(245);
  if ( myPort.available() > 0) {  // If data is available,
    //val = myPort.readStringUntil(13);
    raw_vals = myPort.readString();
    vals = split(raw_vals,'\r');
    for(int n = 0; n < vals.length; n++){
      val = vals[n];
      if(val != null){
        val = val.trim();
        String data[] = split(val, '\t');
        if(data.length > 1){
          temp = float(data[0]);
          light = int(data[1])/4;
          moisture = int(data[2])/4;
          pump = int(data[3]);
          println(moisture);
         for (int i = temp_hist.length-1; i > 0; i--) {
            temp_hist[i] = temp_hist[i-1];
          }
          temp = temp*5;
          int mean_width = 100;
          temp_avg = (temp_avg*mean_width + temp)/(mean_width+1);
          
          temp_hist[0] = height-temp_avg; //(height-(temp/max_temp))/height;
          stroke(10);
          for (int i = 1; i < temp_hist.length; i++) {
            line(i, temp_hist[i], i-1, temp_hist[i-1]);
          }
          
          ////
          
          for (int i = light_hist.length-1; i > 0; i--) {
            light_hist[i] = light_hist[i-1];
          }
          //light_hist[0] = light + 400; //(height-(temp/max_temp))/height;
          light = light + 400; //(height-(temp/max_temp))/height;
          
          light_avg = (light_avg*mean_width + light)/(mean_width+1);
          light_hist[0] = height-light_avg;
          stroke(10);
          for (int i = 1; i < light_hist.length; i++) {
            line(i, light_hist[i], i-1, light_hist[i-1]);
          }
          
        }
      }
    }
  }
}
  
