// Thermistor Variables
float ADCin; // Defines the variable ADCin (ADC input). This is the ADC measurement of the voltage drop of the thermistor.
float Vin; // Defines the variable Vin (Voltage input). This is the measure of the voltage drop of the thermistor.
float T; // Defines the variable T (Temperature measured by the Thermistor).
// Thermistor Constants
float A = -32.3939991375;
float B = 28.347902;
float C = 0.41222751713;
float D = 0.08171291;

// LED Constants
int LEDG = 13; // Pin number of the green LED.
int LEDB = 12; // Pin number of the green LED.
int LEDR = 11; // Pin number of the green LED.
// LED Variable Constants - changed during competition prep period
int LBG = 00; // Green Lower bound value
int UBG = 00; // Green Upper bound
int LBB = 00; // Blue Lower bound
int UBB = 00; // Blue Upper bound
int LBR = 00; // Red Lower bound
int UBR = 00; // Red Upper bound


void setup() {
 // Thermistor Setup
 Serial.begin(9600); // Serial baud rate - bits/second
 
 // LED Setup
 pinMode(LEDG, OUTPUT);
 pinMode(LEDB, OUTPUT);
 pinMode(LEDR, OUTPUT);
} 

void loop() {
// Thermistor functions
ADCin = analogRead(A0); // Reads the ADC value of the pin associated with the thermistor circuit
Vin = ADCin * (4.88759) / 1000; // Converts ADC to Voltage
T = (A + B*Vin) / (1 + C * Vin) + D * pow(Vin, 2); // Converts Voltage to Temperature

Serial.println("Voltage: ");
Serial.print(Vin , 2); // Voltage must be printed to the hundredths place
Serial.println(" V");

Serial.println("Temperature:");
Serial.print(T, 3); // Temperature must be printed to the thousandths place
Serial.println(" C");

// LEDs
if((T >= LBG)&&(T <= UBG)){
  digitalWrite(LEDG, HIGH); // Turns on Green LED
}
else{
  digitalWrite(LEDG, LOW); // Turns off Green LED
}
if((T >= LBB)&&(T <= UBB)){
  digitalWrite(LEDB, HIGH); // Turns on Blue LED
}
else{
  digitalWrite(LEDB, LOW); // Turns off Blue LED
}
if((T >= LBR)&&(T <= UBR)){
  digitalWrite(LEDR, HIGH); // Turns on Red LED
}
else{
  digitalWrite(LEDR, LOW); // Turns on Blue LED
}


delay(3000); // Waits 3 seconds (3000 ms) before looping back again
}
