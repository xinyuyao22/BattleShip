//
// Created by mfbut on 3/11/2019.
//

#include "RandomAI.h"
#include "Attack.h"
#include "Utility.h"

BattleShip::RandomAI::RandomAI(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view) : AiPlayer(
        gameAttributes, view) {
    for(int i = 0; i < gameAttributes.getNumRows(); i++){
        for(int j = 0; j < gameAttributes.getNumCols(); j++){
            std::pair<int, int> firingLocation(i, j);
            firingLocations.push_back(firingLocation);
        }
    }
}

std::unique_ptr<BattleShip::Move> BattleShip::RandomAI::getMove() {
    auto itr = chooseRandom(firingLocations, randomNumberGenerator);
    std::pair<int, int> location = *itr;
    firingLocations.erase(itr);
    return std::make_unique<Attack>(*this, location.first, location.second);
}
