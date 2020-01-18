//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H
#include <functional>
#include <string>
#include <memory>
#include <map>
#include "Move.h"
#include "GameAttributes.h"
#include "View.h"
#include "Board.h"
#include "AttackResult.h"

namespace BattleShip {
class View; //forward declaration
class Move;
class Model;
class Player {
 public:
  Player(const GameAttributes& gameAttributes, View& view);

  const std::string& getName() const;
  void setName(const std::string& name);
  const Board& getBoard() const;
  Board& getBoard();
  const int getId() const;

  virtual std::unique_ptr<BattleShip::Move> getMove() = 0;
  virtual void placeShips() = 0;
  virtual void initializeName() = 0;
  virtual bool allShipsSunk() const;


  virtual BattleShip::AttackResult fireAt(int row, int col);

  Player& getOpponent();
  const Player& getOpponent() const;
  void setOpponent(Player& opponent);

 protected:
  //virtual bool hit(char shipChar);
  static int num_instances;
  const int id;
  std::string name;
  std::map<char, int> shipHealths;
  View& view;
  Board board;
  Player* opponent;
};
}

namespace std{
template <>
class hash<BattleShip::Player&>{
  std::size_t operator()(const BattleShip::Player& player) const{
    return player.getId();
  }
};
}


#endif //BATTLESHIP_PLAYER_H
