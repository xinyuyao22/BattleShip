//
// Created by mfbut on 3/9/2019.
//
#include <utility>
#include "Utility.h"
#include "GameAttributes.h"

int BattleShip::GameAttributes::getNumRows() const {
    return numRows;
}

void BattleShip::GameAttributes::setNumRows(int numRows) {
    GameAttributes::numRows = numRows;
}

int BattleShip::GameAttributes::getNumCols() const {
    return numCols;
}

void BattleShip::GameAttributes::setNumCols(int numCols) {
    GameAttributes::numCols = numCols;
}

BattleShip::GameAttributes::GameAttributes(int numRows, int numCols):numRows(numRows), numCols(numCols) {
}

BattleShip::GameAttributes::GameAttributes(std::istream &in) {
    in >> numRows >> numCols;
    int ns;
    in >> ns;
    for(int i = 0; i < ns; i++){
        char ship;
        int shipHealth;
        in >> ship >> shipHealth;
        shipAttributes.insert(std::make_pair(ship, shipHealth));
    }
}

const std::map<char, int> &BattleShip::GameAttributes::getShipAttributes() const {
    return shipAttributes;
}

BattleShip::GameAttributes::GameAttributes() {
}

int BattleShip::GameAttributes::getShipSize(const char ShipChar) const {
    return shipAttributes.at(ShipChar);
}
