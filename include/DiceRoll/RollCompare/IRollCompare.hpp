#ifndef DICEROLL_IROLLCOMPARE_H
#define DICEROLL_IROLLCOMPARE_H

namespace DiceRoll {
class IRollCompare {
 public:
  virtual char symbol() = 0;
  virtual bool (*compare())(int, int) = 0;
};
}

#endif // DICEROLL_IROLLCOMPARE_H
