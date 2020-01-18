//
// Created by mfbut on 3/10/2019.
//

#ifndef BATTLESHIP_CELL_H
#define BATTLESHIP_CELL_H

namespace BattleShip {
class Cell {
 public:
  Cell(char contents, const char hiddenMarker, const char hitMarker, const char missMarker);
  Cell(char contents);
  char getContents() const;
  void setContents(char contents);
  char getContentsIfHidden() const;
  char getContentsIfVisible() const;
  bool HasBeenFiredAt() const;
  void setHasBeenFiredAt(bool hasBeenFiredAt);
  bool containsShip()const;

 protected:
  char contents;
  bool firedAt;
  const char hiddenMarker;
  const char hitMarker;
  const char missMarker;

};
}

#endif //BATTLESHIP_CELL_H
