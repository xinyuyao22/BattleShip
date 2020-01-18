//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_VIEW_H
#define BATTLESHIP_VIEW_H

#include <unordered_map>
#include "PlayerConfiguration.h"
#include "ShipPlacement.h"
#include "Player.h"
#include "AttackResult.h"
namespace BattleShip {
class Player; //forward declaration
class Model;
class Move;
class View {

 public:
  virtual PlayerConfiguration getPlayerConfiguration() = 0;
  virtual std::string getPlayerName(int i) = 0;
  virtual ShipPlacement getShipPlacement(const Player& player, char shipChar, int shipLen) = 0;
  virtual void updateShipPlacementView(const Player& player) = 0;
  virtual std::pair<int, int> getFiringCoordinate(const BattleShip::Player& attacker) = 0;
  virtual void showWinner(const Player& winner) = 0;
  virtual void showResultOfAttack(const BattleShip::Player& attacker,
                                  const BattleShip::AttackResult& attackResult) = 0;
  virtual void showPlayersBoard(const Player& player) = 0;
  virtual void showPlacementBoard(const Player& player) = 0;
  virtual int getAiChoice() = 0;
};
}
#endif //BATTLESHIP_VIEW_H
