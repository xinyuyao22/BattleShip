//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_HUMANPLAYER_H
#define BATTLESHIP_HUMANPLAYER_H

#include <iostream>
#include "Player.h"
#include "View.h"
#include "GameAttributes.h"
namespace BattleShip {
class Move;
class HumanPlayer : public Player {
 public:
  HumanPlayer(const GameAttributes& gameAttributes, View& view);
  virtual std::unique_ptr<BattleShip::Move> getMove() override;
  virtual void placeShips() override;
  virtual void initializeName() override;
 protected:
};
}

#endif //BATTLESHIP_HUMANPLAYER_H
