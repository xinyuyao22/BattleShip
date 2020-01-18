//
// Created by mfbut on 3/10/2019.
//

#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H
#include <string>
#include <vector>
#include "ShipPlacement.h"
#include "Cell.h"

namespace BattleShip {
class Board {
 public:
  Board(int numRows, int numCols, char blankChar);
  Board(int numRows, int numCols);
  bool canPlaceShipAt(const ShipPlacement& shipPlacement) const;

  int getNumRows() const;
  int getNumCols() const;

  //std::vector<std::string> getHiddenVersion() const;
  //std::vector<std::string> getVisibleVersion() const;

  void AddShip(char shipChar, const ShipPlacement& shipPlacement);
  bool inBounds(int row, int col) const;

  Cell& at(int i, int j);
  const Cell& at(int i, int j) const;


 protected:
  bool inBounds(const ShipPlacement& shipPlacement) const;

  bool between(int value, int low, int high) const;
  bool spacesAreEmpty(const ShipPlacement& shipPlacement) const;

  //members
  std::vector<std::vector<Cell>> boardState;
  const char blankChar;
};
}

#endif //BATTLESHIP_BOARD_H
