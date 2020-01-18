//
// Created by mfbut on 3/11/2019.
//

#ifndef BATTLESHIP_RANDOMAI_H
#define BATTLESHIP_RANDOMAI_H
#include <vector>
#include <algorithm>
#include "AiPlayer.h"

namespace BattleShip {
class RandomAI  : public AiPlayer{
 public:
  RandomAI(const GameAttributes& gameAttributes, View& view);
  virtual std::unique_ptr<Move> getMove() override;
 protected:
  std::vector<std::pair<int, int>> firingLocations;
  //.erase to erase from vector
};
}

#endif //BATTLESHIP_RANDOMAI_H
