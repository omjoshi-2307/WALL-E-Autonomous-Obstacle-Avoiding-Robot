#include <cassert>
#include <iostream>
#include <vector>

std::vector<int> servoWrites;
std::vector<unsigned long> delayCalls;
int pingResult = 42;
void delay(unsigned long ms) { delayCalls.push_back(ms); }

int readPing();
int lookRight();
int lookLeft();
void moveStop();
void moveForward();
void moveBackward();
void turnRight();
void turnLeft();

#include "../code.cpp"

void verifyScan(int angle, int expectedDistance) {
  servoWrites.clear();
  delayCalls.clear();
  pingResult = expectedDistance;
  const int measured = angle == 50 ? lookRight() : lookLeft();
  const int normalized = expectedDistance == 0 ? 250 : expectedDistance;

  assert(measured == normalized);
  assert((servoWrites == std::vector<int>{angle, 115}));
  assert((delayCalls == std::vector<unsigned long>{500, 70, 100, 100}));
}

int main() {
  verifyScan(50, 42);
  verifyScan(170, 42);
  verifyScan(170, 0);
  std::cout << "servo scan host regression tests passed (3 cases)\n";
}
