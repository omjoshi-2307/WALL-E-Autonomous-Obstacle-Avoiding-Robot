#pragma once
using boolean = bool;
#define A0 14
#define A1 15
#define MOTOR12_1KHZ 1
#define MOTOR34_1KHZ 2
#define RELEASE 0
#define FORWARD 1
#define BACKWARD 2
class AF_DCMotor {
public:
  AF_DCMotor(int, int) {}
  void run(int) {}
  void setSpeed(int) {}
};
