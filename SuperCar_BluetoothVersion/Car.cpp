#include "Car.hpp"


 
  Car::Car(byte servoPin,byte MotIN1, byte MotIN2, byte MotENA, byte MotENB = 0, byte MotIN3 = 0, byte MotIN4 = 0)
  {
    _MotIN1 = MotIN1;
    _MotIN2 = MotIN2;
    _MotENA = MotENA;
    _MotENB = MotENB;
    _MotIN3 = MotIN3;
    _MotIN4 = MotIN4;
    _servoPin = servoPin;
    _servoAttached = 0;
    _fw_bw_stop = CAR_STOP;
    _l_r_straight = CAR_STRAIGHT;
  }
  void Car::init(void)
  {
    pinMode(_MotIN1,OUTPUT);
    pinMode(_MotIN2,OUTPUT);
    pinMode(_MotENA,OUTPUT);
    if(_MotENB != 0)
    {
      pinMode(_MotENB,OUTPUT);
      pinMode(_MotIN3,OUTPUT);
      pinMode(_MotIN4,OUTPUT);
    }
    pinMode(_servoPin,OUTPUT);
    if(_servoAttached == 0)
    {
      _servo.attach(_servoPin);
      _servoAttached = 1;
    }
    else
    {
      
    }
    _fw_bw_stop = CAR_STOP;
    _l_r_straight = CAR_STRAIGHT;
  }
  void Car::init(byte SERVO_LEFT,byte SERVO_STRAIGHT,byte SERVO_RIGHT,byte CAR_SPEED, byte _motor_reversed = 0, byte _servo_reversed = 0)
  {
    _SERVO_LEFT=SERVO_LEFT;
    _SERVO_STRAIGHT=SERVO_STRAIGHT;
    _SERVO_RIGHT=SERVO_RIGHT;
    _CAR_SPEED = CAR_SPEED;
    
    pinMode(_MotIN1,OUTPUT);
    pinMode(_MotIN2,OUTPUT);
    pinMode(_MotENA,OUTPUT);
    if(_MotENB != 0)
    {
      pinMode(_MotENB,OUTPUT);
      pinMode(_MotIN3,OUTPUT);
      pinMode(_MotIN4,OUTPUT);
    }
    
    digitalWrite(_MotIN1,LOW);
    digitalWrite(_MotIN2,LOW);
    digitalWrite(_MotENA,LOW);
    if(_MotENB != 0)
    {
      digitalWrite(_MotENB,LOW);
      digitalWrite(_MotIN3,LOW);
      digitalWrite(_MotIN4,LOW);
    }
    
    pinMode(_servoPin,OUTPUT);
    if(_servoAttached == 0)
    {
      _servo.attach(_servoPin);
      _servoAttached = 1;
    }
    else
    {
      
    }
    _fw_bw_stop = CAR_STOP;
    _l_r_straight = CAR_STRAIGHT;
  }
  void Car::move_car(byte fw_bw_or_stop)
  {
    switch(fw_bw_or_stop)
    {
      case CAR_STOP:
        _fw_bw_stop = CAR_STOP;
        //_motor_stop();
        break;
      case CAR_FW:
        _fw_bw_stop = CAR_FW;
       // _motor_fw();
        break;
      case CAR_BW:
        _fw_bw_stop = CAR_BW;
        //_motor_bw()
        break;
      default:
         _fw_bw_stop = CAR_STOP;
         _motor_stop();
        break;
    }
  }
  void Car::steer_car(byte l_r_or_straight)
  {
    switch(l_r_or_straight)
    {
      case CAR_STRAIGHT:
        _l_r_straight = CAR_STRAIGHT;
        //_servo_straight();
        break;
      case CAR_LEFT:
        _l_r_straight = CAR_LEFT;
        //_servo_left();
        break;
      case CAR_RIGHT:
         _l_r_straight = CAR_RIGHT;
        //_servo_right();
        break;
      default:
        _l_r_straight = CAR_STRAIGHT;
        _servo_straight();
        break;
    }
  }
  void Car::go(void)
  {
    switch(_fw_bw_stop)
    {
      case CAR_STOP:
        _motor_stop();
        break;
      case CAR_FW:
        _motor_fw();
        break;
      case CAR_BW:
        _motor_bw();
        break;
      default:
         _fw_bw_stop = CAR_STOP;
         _motor_stop();
        break;
    }
    switch(_l_r_straight)
    {
      case CAR_STRAIGHT:
        _servo_straight();
        break;
      case CAR_LEFT:
        _servo_left();
        break;
      case CAR_RIGHT:
        _servo_right();
        break;
      default:
        _l_r_straight = CAR_STRAIGHT;
        _servo_straight();
        break;
    }
  }
  void Car::_motor_stop(void)
  {
      digitalWrite(_MotIN1,LOW);
      digitalWrite(_MotIN2,LOW);
      digitalWrite(_MotENA,LOW);
      if(_MotENB != 0)
      {
        digitalWrite(_MotENB,LOW);
        digitalWrite(_MotIN3,LOW);
        digitalWrite(_MotIN4,LOW);
      }

  }
  void Car::_motor_fw(void)
  {
    if(_motor_reversed == 0)
    {
      digitalWrite(_MotIN1,LOW);
      digitalWrite(_MotIN2,HIGH);
      analogWrite(_MotENA,_CAR_SPEED);
      if(_MotENB != 0)
      {
        analogWrite(_MotENB,_CAR_SPEED);
        digitalWrite(_MotIN3,LOW);
        digitalWrite(_MotIN4,HIGH);
      }
    }
    else
    {
      digitalWrite(_MotIN1,HIGH);
      digitalWrite(_MotIN2,LOW);
      analogWrite(_MotENA,_CAR_SPEED);
      if(_MotENB != 0)
      {
        analogWrite(_MotENB,_CAR_SPEED);
        digitalWrite(_MotIN3,HIGH);
        digitalWrite(_MotIN4,LOW);
      }
    }
  }
  void Car::_motor_bw(void)
  {
    if(_motor_reversed == 0)
    {
      digitalWrite(_MotIN1,HIGH);
      digitalWrite(_MotIN2,LOW);
      analogWrite(_MotENA,_CAR_SPEED);
      if(_MotENB != 0)
      {
        analogWrite(_MotENB,_CAR_SPEED);
        digitalWrite(_MotIN3,HIGH);
        digitalWrite(_MotIN4,LOW);
      }
    }
    else
    {
      digitalWrite(_MotIN1,LOW);
      digitalWrite(_MotIN2,HIGH);
      analogWrite(_MotENA,_CAR_SPEED);
      if(_MotENB != 0)
      {
        analogWrite(_MotENB,_CAR_SPEED);
        digitalWrite(_MotIN3,LOW);
        digitalWrite(_MotIN4,HIGH);
      }
    }
  }
  void Car::_servo_straight(void)
  {
    if(_servoAttached == 1)
    {
      _servo.write(_SERVO_STRAIGHT);
    }
  }
  void Car::_servo_left(void)
  {
    if(_servoAttached == 1)
    {
      if(_servo_reversed == 0)
      {
        _servo.write(_SERVO_LEFT);
      }
      else
      {
        _servo.write(_SERVO_RIGHT);
      }
    }
  }
  void Car::_servo_right(void)
  {
    if(_servoAttached == 1)
    {
      if(_servo_reversed == 0)
      {
        _servo.write(_SERVO_RIGHT);
      }
      else
      {
        _servo.write(_SERVO_LEFT);
      }
    }
  }