#include <OneWire.h>
#include <DallasTemperature.h>  
#define ONE_WIRE_BUS 45
#include <Adafruit_GFX.h>
#include <Servo.h>

Servo lidServo;


#define S0_PIN 23
#define S1_PIN 25
#define S2_PIN 27
#define S3_PIN 29
#define OUT_PIN 31
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#include <Keypad.h>

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);


const int Solonid_Half_IN = 35; // Relay
const int Solonid_Half_OUT = 37;
const int Solonid_Customer = 39;
const int Level_Sensor= 33;
const int Buzzer = 2;


// need to adjest the correct pin out 
const int Cup_Level_Sensor = 34;
 
int count =0;
 bool testingEnable = false;
int z = 0;

int value;
int Half_L_Count;

bool HalF_Enable = true;
bool CostomerEnable = true;
bool DoorCloseEnable = false;
bool DoorEnable = true;
float readpH();


const byte ROWS = 4;      // Number of rows on the keypad
const byte COLS = 4;      // Number of columns on the keypad
const int BUFFER_SIZE = 3; // Buffer size for storing the entered digits (maximum 2 digits + null terminator)


char key;



// Define the keypad matrix
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Pin numbers connected to the keypad rows and columns
byte rowPins[ROWS] = {10, 9, 8, 7};     // Connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 5, 4, 3};     // Connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
char buffer[BUFFER_SIZE]; // Buffer to store the entered digits (maximum 2 digits + null terminator)
int bufferIndex = 0; // Index to keep track of the buffer position


LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

float pH_value;
int weight, density;
int volume = 200;
const int pHPin = A1;    // Analog pin for pH sensor
const int gasSensorPin = A0;
const float pHCalibrationValue = 21.34 - 0.7;  // Calibration value for pH sensor


void setup() {
  lcd.init();   // initialize the lcd 
  lcd.init();
  Wire.begin();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("POOR THE MILK");
  lcd.setCursor(2,1);
  lcd.print("FOR TESTING");

  Serial.begin(115200);// Start serial communication
  sensors.begin(); // Initialize the temperature sensors

  int sensorValue = analogRead(gasSensorPin);// Read the gas sensor value
  float voltage = sensorValue * (5.0 / 1023.0);// Convert the sensor value to a voltage
  float gasConcentration = (2.5 - voltage) / 0.2;// Calculate the gas concentration(adjust the parameters for specific gases) 

    // Set the S0, S1, S2, S3 Pins as Output
  pinMode(S0_PIN, OUTPUT);
  pinMode(S1_PIN, OUTPUT);
  pinMode(S2_PIN, OUTPUT);

    pinMode(Solonid_Half_IN,OUTPUT); 
   pinMode(Solonid_Half_OUT,OUTPUT);
    pinMode(Solonid_Customer,OUTPUT);
    pinMode(Buzzer,OUTPUT);

    pinMode(Level_Sensor, INPUT);
    pinMode( Cup_Level_Sensor, INPUT);
   
    lidServo.attach(47);
    lidServo.write(0);



  pinMode(S3_PIN, OUTPUT);
  //Set OUT_PIN as Input
  pinMode(OUT_PIN, INPUT);
  // Set Pulse Width scaling to 20%
  digitalWrite(S0_PIN, HIGH);
  digitalWrite(S1_PIN, LOW);
  // Enabl UART for Debugging
  Serial.begin(9600);
  delay(3000);
  lcd.clear();
}

void loop(){
  lcd.setCursor(1,0);
  lcd.print("PRESS A TO ");
  lcd.setCursor(2,1);
  lcd.print("TESTING");
  key = keypad.getKey();
  if(key=='A'){
     testingEnable = true;
  }
  
  if(testingEnable){
  Testing();
  }

}


