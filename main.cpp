#include "Controller.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main(int argc, char** argv) {
  using namespace BattleShip;
  Controller Controller;
  if(argc == 3){
    int seed = atoi(argv[2]);
    Controller.setupGame(argv[1], seed);
  }else{
    Controller.setupGame(argv[1]);
  }
  Controller.playGame();

  return 0;
}
