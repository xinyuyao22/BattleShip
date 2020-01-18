//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_CONTROLLER_H
#define BATTLESHIP_CONTROLLER_H
#include <memory>
#include <string>
#include "Model.h"
#include "View.h"
#include "Player.h"
#include "Move.h"
namespace BattleShip {
class Controller {
 public:
  Controller();
  void setupGame(const std::string& GameConfigurationFile, int seed);
  void setupGame(const std::string& GameConfigurationFile);
  void setupGame();
  void playGame();

 protected:
  bool hasBeenSetUp;
  Model model;
  std::unique_ptr<View> view;

};
}

#endif //BATTLESHIP_CONTROLLER_H
