#include <SparkFun_TB6612.h>
#define AIN1 A0
#define AIN2 A1
#define BIN1 A2
#define BIN2 A3
#define STBY A4
#define PWMA 11
#define PWMB 10
const int offsetA = 1;
const int offsetB = 1;
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

#include <EEPROM.h>
int motor_speed = 107;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);       // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(9600);  //Change this baudrate as per your bluetooth baudrate. Connect bluetooth on digital pin 2(RX) and 3(TX) for Uno/Nano and on Serial3 pins for Mega.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println(EEPROM.read(0));
  Serial.println("Setup Complete. Ready for Commands.");
  pinMode(13, OUTPUT);
}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.      //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  if (GamePad.isUpPressed())
  {
    Serial.println("UP");
    motor1.drive(112,0); 
    motor2.drive(100,0);
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  } else if (GamePad.isDownPressed())
  {
    Serial.println("DOWN");
    motor1.drive(-107,0); 
    motor2.drive(-100,0);
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  } else if (GamePad.isLeftPressed())
  {
    Serial.println("Left");
    motor1.drive(128,0); 
    motor2.drive(-128,0);
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  } else if (GamePad.isRightPressed())
  {
    Serial.println("Right");
    motor1.drive(-128,0); 
    motor2.drive(128,0);
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  } else {
    brake(motor1, motor2);
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  }
  if (GamePad.isTrianglePressed())
  {
    Serial.println("Triangle");
    digitalWrite(13, HIGH);
    motor_speed = motor_speed + 1;  
    Serial.println(motor_speed);
    delay(30);
  }
  if (GamePad.isCrossPressed())
  {
    Serial.println("Cross");
    digitalWrite(13, HIGH);
    motor_speed = motor_speed - 1;  
    Serial.println(motor_speed1);
    delay(30);
  }
  else {
    digitalWrite(13, LOW);
    if (motor_speed != 100){
      EEPROM.update(0, motor_speed1);
    }
    delay(30);
  }
}
