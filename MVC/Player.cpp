//
// Created by mfbut on 3/9/2019.
//

#include "Player.h"

int BattleShip::Player::num_instances = 1;

BattleShip::Player::Player(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view) :id(num_instances), shipHealths(gameAttributes.getShipAttributes()), view(view), board(gameAttributes.getNumRows(), gameAttributes.getNumCols()) {
    ++num_instances;
}

const std::string &BattleShip::Player::getName() const {
    return name;
}

void BattleShip::Player::setName(const std::string &name) {
    Player::name = name;
}

const BattleShip::Board &BattleShip::Player::getBoard() const {
    return board;
}

BattleShip::Board &BattleShip::Player::getBoard() {
    return board;
}

const int BattleShip::Player::getId() const {
    return id;
}

BattleShip::Player &BattleShip::Player::getOpponent() {
    return *opponent;
}

const BattleShip::Player &BattleShip::Player::getOpponent() const {
    return *opponent;
}

void BattleShip::Player::setOpponent(BattleShip::Player &opponent) {
    Player::opponent = &opponent;
}

bool BattleShip::Player::allShipsSunk() const {
    for(auto ship : shipHealths){
        if(ship.second != 0){
            return false;
        }
    }
    return true;
}

BattleShip::AttackResult BattleShip::Player::fireAt(int row, int col) {
    opponent->getBoard().at(row, col).setHasBeenFiredAt(true);
    if(opponent->getBoard().at(row, col).containsShip()){
        char shipChar = opponent->getBoard().at(row, col).getContents();
        if(shipHealths[shipChar] != 0) {
            shipHealths[shipChar] -= 1;
        }
        opponent->getBoard().at(row, col).setContents('X');
        return AttackResult(true, shipHealths[shipChar] == 0, shipChar);
    } else{
        opponent->getBoard().at(row, col).setContents('O');
        return AttackResult(false, false, board.at(row, col).getContentsIfVisible());
    }
}

//bool BattleShip::Player::hit(char shipChar) {
  //  if(shipHealths[shipChar] != 0) {
    //    shipHealths[shipChar] -= 1;
      //  return true;
    //}else{
      //  return false;
    //}
//}




