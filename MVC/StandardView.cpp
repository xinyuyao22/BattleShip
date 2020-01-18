//
// Created by mfbut on 3/9/2019.
//

#include <algorithm>
#include <vector>
#include <cctype>
#include "StandardView.h"
#include "Utility.h"

BattleShip::StandardView::StandardView(std::istream &in, std::ostream &out): in(in), out(out) {

}

BattleShip::StandardView::StandardView(): in(std::cin),out(std::cout) {
}

BattleShip::PlayerConfiguration BattleShip::StandardView::getPlayerConfiguration() {
    out << "What type of game do you want to play?" << std::endl;
    out << "1. Human vs Human" << std::endl;
    out << "2. Human vs AI" << std::endl;
    out << "3. AI vs AI" << std::endl;
    out << "Your choice: " << std::endl;

    int choice = 0;
    in >> choice;
    if(choice == 1){
        PlayerConfiguration PlayerConfiguration(2, 0);
        return PlayerConfiguration;
    }else if(choice == 2){
        PlayerConfiguration PlayerConfiguration(1, 1);
        return  PlayerConfiguration;
    }else {
        PlayerConfiguration PlayerConfiguration(0, 2);
        return PlayerConfiguration;
    }
}

std::string BattleShip::StandardView::getPlayerName(int i) {
    out << "Player " <<  i << " please enter your name:" << std::endl;
    std::string name;
    in >> name;
    return name;
}

ShipPlacement BattleShip::StandardView::getShipPlacement(const BattleShip::Player &player, char shipChar, int shipLen) {
    out << player.getName() <<", do you want to place " << shipChar << " horizontally or vertically?" << std::endl;
    out << "Enter h for horizontal or v for vertical" << std::endl;
    out << "Your choice:" << std::endl;
    char orientation;
    in >> orientation;
    out << ' ' << player.getName();
    out << ", enter the row and column you want to place " << shipChar << ", which is " << shipLen << " long, at with a space in between row and col:";
    out << std::endl;
    int rowStart, colStart;
    int rowEnd, colEnd;
    in >> rowStart >> colStart;
    if(orientation == 'h'){
        rowEnd = rowStart;
        colEnd = colStart + shipLen - 1;
    }else if (orientation == 'v'){
        rowEnd = rowStart + shipLen - 1;
        colEnd = colStart;
    }
    return ShipPlacement(rowStart, colStart, rowEnd, colEnd);
}

void BattleShip::StandardView::printBoard(const std::vector<std::string> &board) {
    out << ' ';
    for(size_t i = 0; i < board[i].length(); i++){
        out << i;
    }
    out << std::endl;
    for(size_t i = 0; i < board.size(); i++){
        out << i << board[i] << std::endl;
    }
}

void BattleShip::StandardView::printBoardAsVisible(const BattleShip::Board &board) {
    out << ' ';
    for(int i = 0; i < board.getNumCols(); i++){
        out << ' ' << i ;
    }
    out << ' ' << std::endl;
    for(int i = 0; i < board.getNumRows(); i++){
        out << i;
        for(int j = 0; j < board.getNumCols(); j++){
            out << ' ' << board.at(i,j).getContentsIfVisible();
        }
        out << ' ' << std::endl;
    }
}

void BattleShip::StandardView::printBoardAsObscured(const BattleShip::Board &board) {
    out << ' ';
    for(int i = 0; i < board.getNumCols(); i++){
        out << ' ' << i;
    }
    out << ' ' << std::endl;
    for(int i = 0; i < board.getNumRows(); i++){
        out << i;
        for(int j = 0; j < board.getNumCols(); j++){
            out << ' ' << board.at(i,j).getContentsIfHidden();
        }
        out << ' ' << std::endl;
    }

}

void BattleShip::StandardView::showPlacementBoard(const BattleShip::Player &player) {
    out << player.getName() << "'s Board" << std::endl;
    printBoardAsVisible(player.getBoard());
}

int BattleShip::StandardView::getAiChoice() {
    out << "What AI do you want?" << std::endl;
    out << "1. Cheating AI" << std::endl;
    out << "2. Random AI" << std::endl;
    out << "3. Hunt Destroy AI" << std::endl;
    out << "Your choice:" << std::endl;
    int choice = 0;
    in >> choice;
    return choice;
}

void BattleShip::StandardView::showPlayersBoard(const BattleShip::Player &player) {
    out << player.getName() << "'s Firing Board" << std::endl;
    printBoardAsObscured(player.getOpponent().getBoard());
    out << player.getName() << "'s Placement Board" << std::endl;
    printBoardAsVisible(player.getBoard());
}

std::pair<int, int> BattleShip::StandardView::getFiringCoordinate(const BattleShip::Player &attacker) {
    out << attacker.getName() << ", where would you like to fire?" << std::endl;
    out << "Enter your attack coordinate in the form row col:" << std::endl;
    out << ' ';
    std::pair<int, int> location;
    in >> location.first >> location.second;
    return location;
}

void BattleShip::StandardView::updateShipPlacementView(const BattleShip::Player &player) {
    out << ' ';
    printBoardAsVisible(player.getBoard());
}

void BattleShip::StandardView::showResultOfAttack(const BattleShip::Player &attacker,
                                                  const BattleShip::AttackResult &attackResult) {
    if(!attackResult.hit){
        out << "Missed." << std::endl;
    }else {
        out << attacker.getName() << " hit " << attacker.getOpponent().getName() << "'s " << attackResult.shipChar << "!";
        out << std::endl;
        if(attackResult.destroyed){
            out << attacker.getName() << " destroyed " << attacker.getOpponent().getName() << "'s " << attackResult.shipChar << "!";
            out << std::endl;
        }
    }
}

void BattleShip::StandardView::showWinner(const BattleShip::Player &winner) {
    out << winner.getName() << " won the game!" << std::endl;
}
