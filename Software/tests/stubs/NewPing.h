#pragma once
extern int pingResult;
class NewPing {
public:
  NewPing(int, int, int) {}
  int ping_cm() { return pingResult; }
};
