//
// Created by mfbut on 3/11/2019.
//

#include <algorithm>
#include "HuntDestroyAI.h"
#include "Attack.h"
#include "Utility.h"

std::vector<std::pair<int, int>>
BattleShip::HuntDestroyAI::getSurroundingLocations(const std::pair<int, int> &center) const {
    int i = center.first;
    int j = center.second;
    std::vector<std::pair<int, int>> surroundingLocations;
    surroundingLocations.emplace_back(i, j-1);
    surroundingLocations.emplace_back(i-1, j);
    surroundingLocations.emplace_back(i, j+1);
    surroundingLocations.emplace_back(i+1, j);
    return surroundingLocations;
}

BattleShip::HuntDestroyAI::HuntDestroyAI(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view)
        : RandomAI(gameAttributes, view) {
}

std::unique_ptr<BattleShip::Move> BattleShip::HuntDestroyAI::getMove() {
    std::pair<int, int> location;
    if(!priorityFiringQueue.empty()){
        location = priorityFiringQueue.front();
        priorityFiringQueue.erase(priorityFiringQueue.begin());
        firingLocations.erase(std::remove(firingLocations.begin(), firingLocations.end(), location), firingLocations.end());

    }else{
        auto itr = chooseRandom(firingLocations, randomNumberGenerator);
        location = *itr;
        firingLocations.erase(itr);
    }
    if(opponent->getBoard().at(location.first, location.second).containsShip()){
        auto surroundingLocations = getSurroundingLocations(std::pair<int, int>(location.first, location.second));
        for(auto surroundingLocation : surroundingLocations){
            if(contains(surroundingLocation, firingLocations) && !contains(surroundingLocation, priorityFiringQueue) && surroundingLocation.first > -1 && surroundingLocation.first < board.getNumRows() && surroundingLocation.second > -1 && surroundingLocation.second < board.getNumCols()) {
                priorityFiringQueue.push_back(surroundingLocation);
                firingLocations.erase(std::remove(firingLocations.begin(), firingLocations.end(), surroundingLocation), firingLocations.end());
            }
        }
    }
    return std::make_unique<Attack>(*this, location.first, location.second);
}
