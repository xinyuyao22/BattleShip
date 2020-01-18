//
// Created by mfbut on 3/10/2019.
//

#include "Board.h"

int BattleShip::Board::getNumRows() const {
    return boardState.size();
}

int BattleShip::Board::getNumCols() const {
    return boardState.front().size();
}

BattleShip::Board::Board(int numRows, int numCols, char blankChar) :
        boardState(numRows, std::vector<Cell>(numCols, {blankChar})),
        blankChar(blankChar) {
}

BattleShip::Board::Board(int numRows, int numCols) : Board(numRows, numCols, '*') {}

bool BattleShip::Board::canPlaceShipAt(const ShipPlacement &shipPlacement) const {
    return spacesAreEmpty(shipPlacement);
}

BattleShip::Cell &BattleShip::Board::at(int i, int j) {
    return boardState.at(i).at(j);
}

const BattleShip::Cell &BattleShip::Board::at(int i, int j) const {
    return const_cast<Board*>(this)->at(i,j);
}

void BattleShip::Board::AddShip(char shipChar, const ShipPlacement &shipPlacement) {
    for (int i = shipPlacement.rowStart; i < shipPlacement.rowEnd + 1; i++) {
        for (int j = shipPlacement.colStart; j < shipPlacement.colEnd + 1; j++) {
            at(i, j).setContents(shipChar);
        }
    }
}

//std::vector<std::string> BattleShip::Board::getHiddenVersion() const {
//  std::vector<std::string> board;
//for(int i = 0; i < numRows; i++){
//  std::stringstream cells;
//for(int j = 0; j < numCols; j++){
//  cells << at(i,j).getContentsIfHidden();
//}
//board.push_back(cells.str());
//}
//return board;
//}

//std::vector<std::string> BattleShip::Board::getVisibleVersion() const {
//  std::vector<std::string> board;
//for(int i = 0; i < numRows; i++){
//  std::stringstream cells;
//for(int j = 0; j < numCols; j++){
//  cells << at(i,j).getContentsIfVisible();
//}
//board.push_back(cells.str());
//}
//return board;
//}

bool BattleShip::Board::inBounds(int row, int col) const {
    if (!between(row, 0, getNumRows() - 1)) {
        return false;
    }
    if (!between(col, 0, getNumCols() - 1)) {
        return false;
    }
    return true;
}

bool BattleShip::Board::inBounds(const ShipPlacement &shipPlacement) const {
    return inBounds(shipPlacement.rowStart, shipPlacement.colStart) &&
           inBounds(shipPlacement.rowEnd, shipPlacement.colEnd);
}

bool BattleShip::Board::between(int value, int low, int high) const {
    if (value < low) {
        return false;
    }
    return value <= high;
}

bool BattleShip::Board::spacesAreEmpty(const ShipPlacement &shipPlacement) const {
    for (int i = shipPlacement.rowStart; i < shipPlacement.rowEnd + 1; i++) {
        for (int j = shipPlacement.colStart; j < shipPlacement.colEnd +1; j++) {
            if (at(i, j).getContentsIfVisible() != blankChar) {
                return false;
            }
        }
    }
    return true;
}
