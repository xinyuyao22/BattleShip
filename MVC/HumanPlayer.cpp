//
// Created by mfbut on 3/9/2019.
//

#include <utility>
#include "HumanPlayer.h"
#include "ShipPlacement.h"
#include "Attack.h"

BattleShip::HumanPlayer::HumanPlayer(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view) : Player(
        gameAttributes, view) {
}

void BattleShip::HumanPlayer::placeShips() {
    ShipPlacement shipPlacement;
    view.updateShipPlacementView(*this);
    for (const auto &ship : shipHealths) {
        do {
            char shipChar = ship.first;
            int shipLen = ship.second;
            shipPlacement = view.getShipPlacement(*this, shipChar, shipLen);
        } while (!getBoard().canPlaceShipAt(shipPlacement));
        board.AddShip(ship.first, shipPlacement);
        view.updateShipPlacementView(*this);
    }
}



void BattleShip::HumanPlayer::initializeName() {
    name = view.getPlayerName(id);
}

std::unique_ptr<BattleShip::Move> BattleShip::HumanPlayer::getMove() {
    view.showPlayersBoard(*this);
    std::pair<int, int> location = view.getFiringCoordinate(*this);
    return std::make_unique<Attack>(*this, location.first, location.second);
}
