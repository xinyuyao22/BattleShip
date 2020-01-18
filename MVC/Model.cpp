//
// Created by mfbut on 3/9/2019.
//

#include <fstream>
#include <algorithm>
#include "Model.h"


void BattleShip::Model::loadGameConfigurationFromFile(const std::string &gameConfigurationFile) {
    std::ifstream myFile(gameConfigurationFile);
    gameAttributes = GameAttributes(myFile);
}

const BattleShip::GameAttributes &BattleShip::Model::getGameAttributes() const {
    return gameAttributes;
}

const std::vector<std::unique_ptr<BattleShip::Player>> &BattleShip::Model::getPlayers() const {
    return players;
}

BattleShip::Model::Model() {
    playerTurn = 0;
    forcedGameOver = false;
}

BattleShip::Player &BattleShip::Model::getAttackingPlayer() {
    return *players[playerTurn];
}

const BattleShip::Player &BattleShip::Model::getAttackingPlayer() const {
    return *players[playerTurn];
}

BattleShip::Player &BattleShip::Model::getDefendingPlayer() {
    return players[playerTurn]->getOpponent();
}

const BattleShip::Player &BattleShip::Model::getDefendingPlayer() const {
    return players[playerTurn]->getOpponent();
}

bool BattleShip::Model::isGameOver() const {
    for(int i = 0; i < 2; i++){
        if(players[i]->allShipsSunk()){
            return true;
        }
    }
    return false;
}

void BattleShip::Model::changeTurn() {
    playerTurn = (playerTurn + 1) % 2;
}

std::unique_ptr<BattleShip::Move> BattleShip::Model::getNextMove() {
    auto attack = getAttackingPlayer().getMove();
    changeTurn();
    return attack;
}

void BattleShip::Model::SetOpponents() {
        players.front()->setOpponent(*(players.back().get()));
        players.back()->setOpponent(*(players.front().get()));
}

BattleShip::Player &BattleShip::Model::getWinner() {
        if(!players[0]->allShipsSunk()){
            return *players[1];
        }else{
            return *players[0];
        }
}
