//
// Created by mfbut on 3/10/2019.
//

#ifndef BATTLESHIP_ATTACK_H
#define BATTLESHIP_ATTACK_H
#include "Move.h"
#include "Player.h"
namespace BattleShip {
class Attack : public Move {
 public:
  Attack(BattleShip::Player& attacker, int row, int col);
  virtual void enact(Model& model, View& view) override;
  virtual bool isValid() const override;
  const int getRow() const;
  const int getCol() const;
 protected:
  const int row, col;

};
}

#endif //BATTLESHIP_ATTACK_H
