//
// Created by mfbut on 3/10/2019.
//

#include "Attack.h"

const int BattleShip::Attack::getRow() const {
    return row;
}

const int BattleShip::Attack::getCol() const {
    return col;
}

void BattleShip::Attack::enact(BattleShip::Model &model, BattleShip::View &view) {
    auto attackResult = moveMaker.fireAt(row, col);
    view.showPlayersBoard(moveMaker);
    view.showResultOfAttack(moveMaker,attackResult);
}

bool BattleShip::Attack::isValid() const {
    if(moveMaker.getOpponent().getBoard().at(row, col).HasBeenFiredAt() == true){
        return false;
    }
    return true;
}

BattleShip::Attack::Attack(BattleShip::Player &attacker, int row, int col): Move(attacker), row(row),col(col) {
}
