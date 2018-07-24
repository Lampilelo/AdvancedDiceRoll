#ifndef DICEROLL_COMPARERS_H
#define DICEROLL_COMPARERS_H

#include "DiceRoll/stdafx.hpp"
#include "DiceRoll/RollCompare/IRollCompare.hpp"

namespace DiceRoll {
class PrioritizeLower : public IRollCompare {
  static const char symbol_ = '<';
  static bool compare_(int a, int b) { return a < b; }

 public:
  inline char symbol() { return symbol_; }
  inline bool (*compare())(int, int) { return compare_; }
};

class PrioritizeHigher : public IRollCompare {
  static const char symbol_ = '>';
  static bool compare_(int a, int b) { return a > b; }

 public:
  inline char symbol() { return symbol_; }
  inline bool (*compare())(int, int) { return compare_; }
};
}

#endif // DICEROLL_COMPARERS_H
