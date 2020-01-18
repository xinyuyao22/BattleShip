//
// Created by mfbut on 3/10/2019.
//

#ifndef BATTLESHIP_ENDGAME_H
#define BATTLESHIP_ENDGAME_H
#include "Move.h"

namespace BattleShip{
class EndGame : public Move{
 public:
  EndGame(Player& moveMaker);
  virtual void enact(Model& model, View& view) override;
  virtual bool isValid() const override;
};
}

#endif //BATTLESHIP_ENDGAME_H
