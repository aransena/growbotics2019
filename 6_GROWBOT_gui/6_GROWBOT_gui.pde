// Aran Sena 2019

import processing.serial.*;

Serial myPort;  // Create object from Serial class

String val;      // Data received from the serial port
String raw_vals;
String vals[];

float temp;
float temp_avg = 0;
float[] temp_hist;

float light;
float light_avg = 0;
float[] light_hist;

float moisture;
float moisture_avg = 0;
float[] moisture_hist;

int pump;
int[] pump_hist;

float mean_width = 100; // For moving average

void setup() 
{
  size(800, 500);
  temp_hist = new float[width];
  light_hist = new float[width];
  moisture_hist = new float[width];
  pump_hist = new int[width];
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);

}

void draw()
{ 
  if ( myPort.available() > 0) {            // If data is available,
    raw_vals = myPort.readString();         // Read all data available
    vals = split(raw_vals,'\r');            // Split the data by line breaks
    for(int n = 0; n < vals.length; n++){   // For each line of data (Temp, Light, Moisture, Pump Status)
      val = vals[n];                        // Current data is the nth entry from vals
        
      if(val != null){                      // If valid
        val = val.trim();                   // Trim any whitespace
        String data[] = split(val, '\t');   // Split the string data based on tab delimiter
      
        if(data.length > 3){                // If it is a full data set (Temp, Light, Moisture, Pump status)
          background(245);                  // Redraw screen
          temp = float(data[0]);
          light = float(data[1])/4;
          moisture = float(data[2])/4;
          pump = int(data[3]);
          
         // Plot data collected
         textSize(15);
         fill(0);
         // Temperature
         for (int i = temp_hist.length-1; i > 0; i--) {
            temp_hist[i] = temp_hist[i-1];
          }
          temp = temp*5;
          temp_avg = (temp_avg*mean_width + temp)/(mean_width+1);
          fill(255,0,0);
          stroke(255,0,0);
          text("Temperature", width-100, height-temp_avg-20);
          line(0,height-temp_avg,width,height-temp_avg);
          temp_hist[0] = height-temp_avg;
          for (int i = 1; i < temp_hist.length; i++) {
            line(i, temp_hist[i], i-1, temp_hist[i-1]);
          }
          
          // Light
          for (int i = light_hist.length-1; i > 0; i--) {
            light_hist[i] = light_hist[i-1];
          }
          light = light + 100;
          light_avg = (light_avg*mean_width + light)/(mean_width+1);
          fill(0,255,0);
          stroke(0,255,0);
          text("Light", width-80, height-light_avg-20);
          line(0,height-(light_avg),width,height-(light_avg));
          light_hist[0] = height-light_avg;
          for (int i = 1; i < light_hist.length; i++) {
            line(i, light_hist[i], i-1, light_hist[i-1]);
          }
          
          // Moisture
          for (int i = moisture_hist.length-1; i > 0; i--) {
            moisture_hist[i] = moisture_hist[i-1];
          }
          moisture = moisture + 200;
          moisture_avg = (moisture_avg*mean_width + moisture)/(mean_width+1);
          println(moisture_avg);
          stroke(0,0,255);
          fill(0,0,255);
          text("Moisture", width-80, height-moisture_avg-20);
          line(0,height-moisture_avg,width,height-moisture_avg);
          moisture_hist[0] = height-moisture_avg;
          for (int i = 1; i < moisture_hist.length; i++) {
            line(i, moisture_hist[i], i-1, moisture_hist[i-1]);
          }
          
          // Pump Status        
          for (int i = pump_hist.length-1; i > 0; i--) {
            pump_hist[i] = pump_hist[i-1];
          }
          pump = pump*10 + 400;
          fill(0,0,0);
          stroke(10);
          text("Pump Status", width-100, height-pump-20);
          line(0,height-pump,width,height-pump);
          pump_hist[0] = height-pump;
          for (int i = 1; i < pump_hist.length; i++) {
            line(i, pump_hist[i], i-1, pump_hist[i-1]);
          }
          
      }
      }
    }
  }
}
  
