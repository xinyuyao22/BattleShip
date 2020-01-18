//
// Created by mfbut on 3/11/2019.
//
#include <stdexcept>
#include "CheatingAI.h"
#include "Attack.h"

BattleShip::CheatingAI::CheatingAI(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view) : AiPlayer(
        gameAttributes, view) {
}

std::unique_ptr<BattleShip::Move> BattleShip::CheatingAI::getMove() {
    for(int i = 0; i < board.getNumCols(); i++) {
        for (int j = 0; j < board.getNumRows(); j++) {
            if (opponent->getBoard().at(j, i).containsShip()) {
                std::pair<int, int> location(j, i);
                return std::make_unique<Attack>(*this, location.first, location.second);
            }
        }
    }
    throw std::out_of_range("Not in bounds");
}
