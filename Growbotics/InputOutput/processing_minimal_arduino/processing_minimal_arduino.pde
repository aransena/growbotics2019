// Aran Sena 2019

import processing.serial.*;

// Create object from Serial class
Serial myPort;  

float light_history[];
float plot_avg = 0;

void setup() {
  // Define the size of our interface window
  size(500, 300);
  // Connect to the serial port
  int dev_ind = 0;
  String portName = Serial.list()[dev_ind]; 
  myPort = new Serial(this, portName, 9600);
  
  // Define an array to store a history of light values for plotting
  light_history = new float[width];
}

void draw() { 
  // If data is available,
  if ( myPort.available() > 0) {

    // Read all data available
    String all_data[] = split(myPort.readString(), '\r');
    for (int n = 0; n < all_data.length; n++) {
      String string_val = all_data[n];
      string_val = string_val.trim();
      // If valid
      if (string_val != null && string_val.length()>0) { 
        // Convert to float
        float light_val = float(string_val);
        // Update stored previous values to make space for the new value
        for (int i = light_history.length-1; i > 0; i--) {
            light_history[i] = light_history[i-1];
        }
        // Scale the incoming data to the plot window
        float plot_val = height*(1-light_val/1024);
        // Compute a moving average to smooth the signal
        plot_avg = (plot_avg * 200. + plot_val) / 201.;
        // Add the smooth signal to the history
        light_history[0] = plot_avg;
        // Clear the scene
        background(255);
        // Plot the data as a series of connect lines
        for (int i = light_history.length - 1; i > 1 ; i--) {
            line(width-i, light_history[i], width-i+1, light_history[i-1]);
          }
      }
    }
  }
}
