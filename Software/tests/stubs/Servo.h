#pragma once
#include <vector>
extern std::vector<int> servoWrites;
class Servo {
public:
  void attach(int) {}
  void write(int angle) { servoWrites.push_back(angle); }
};
