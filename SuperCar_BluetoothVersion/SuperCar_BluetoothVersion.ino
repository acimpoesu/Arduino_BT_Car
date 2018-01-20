#include "Car.hpp"/**/#define BLUETOOTH_STOP  'S'#define BLUETOOTH_FW    'F'#define BLUETOOTH_BW    'B'#define BLUETOOTH_STRAIGHT  'T'#define BLUETOOTH_LEFT      'L'#define BLUETOOTH_RIGHT     'R'const byte MotIN1=4, MotIN2=5, MotENA=6, MotENB=0, MotIN3=0, MotIN4=0, myServoPin=9;char bluetoothIn = 0;Car GoGoCar(myServoPin,MotIN1,MotIN2,MotENA,0,0,0);void setup() {  GoGoCar.init();  Serial.begin(9600);}void loop() {  /*Bluetooth code goes here.*/  if(Serial.available())  {    bluetoothIn = Serial.read();    }    /*Check incoming command.*/  if(bluetoothIn == BLUETOOTH_STOP)  {      GoGoCar.move_car(CAR_STOP);      bluetoothIn = 0;  }  else if(bluetoothIn == BLUETOOTH_FW)  {      GoGoCar.move_car(CAR_FW);      bluetoothIn = 0;  }  else if(bluetoothIn == BLUETOOTH_BW)  {      GoGoCar.move_car(CAR_BW);      bluetoothIn = 0;  }  else  {    /*wait*/  }    if(bluetoothIn == BLUETOOTH_STRAIGHT)  {      GoGoCar.steer_car(CAR_STRAIGHT);      bluetoothIn = 0;  }  else if(bluetoothIn == BLUETOOTH_LEFT)  {      GoGoCar.steer_car(CAR_LEFT);      bluetoothIn = 0;  }  else if(bluetoothIn == BLUETOOTH_RIGHT)  {      GoGoCar.steer_car(CAR_RIGHT);      bluetoothIn = 0;  }  else  {    /*wait*/  }    /*Car moves here.*/  GoGoCar.go();  delay(100);}