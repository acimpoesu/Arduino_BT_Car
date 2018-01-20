#ifndef CAR_HPP_
#define CAR_HPP_

#include <Servo.h>
#include <Arduino.h>

#define CAR_STOP  0
#define CAR_FW  1
#define CAR_BW 2
#define CAR_STRAIGHT  3
#define CAR_LEFT 4
#define CAR_RIGHT  5

class Car {
  
  private: byte _SERVO_LEFT=160,_SERVO_STRAIGHT=90,_SERVO_RIGHT=20,_CAR_SPEED = 120,_CURRENT_SPEED = 0,_CURRENT_DIR = CAR_STOP;
  private: byte _MotIN1, _MotIN2, _MotENA, _MotENB = 0, _MotIN3, _MotIN4, _servoPin,_servoAttached,_fw_bw_stop,_l_r_straight,_motor_reversed = 0, _servo_reversed = 0;
  private: Servo _servo;
  public: Car(byte servoPin,byte MotIN1, byte MotIN2, byte MotENA, byte MotENB = 0, byte MotIN3 = 0, byte MotIN4 = 0);
  public: void init(void);
  public: void init(byte SERVO_LEFT,byte SERVO_STRAIGHT,byte SERVO_RIGHT,byte CAR_SPEED, byte _motor_reversed = 0, byte _servo_reversed = 0);
  public: void move_car(byte fw_bw_or_stop);
  public: void steer_car(byte l_r_or_straight);
  public: void go(void);
  
  private:
    void _motor_stop(void);
    void _motor_fw(void);
    void _motor_bw(void);
    void _servo_straight(void);
    void _servo_left(void);
    void _servo_right(void);
};

#endif CAR_HPP_