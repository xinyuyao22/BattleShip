//
// Created by mfbut on 3/9/2019.
//

#include <stdexcept>
#include <vector>
#include <sstream>
#include "PlayerConfiguration.h"
#include "Controller.h"
#include "HumanPlayer.h"
#include "AiPlayer.h"
#include "StandardView.h"
#include "CheatingAI.h"
#include "RandomAI.h"
#include "HuntDestroyAI.h"

BattleShip::Controller::Controller(): view(std::make_unique<StandardView>()) {
}

void BattleShip::Controller::setupGame() {
    hasBeenSetUp = true;

    PlayerConfiguration playerConfiguration = view->getPlayerConfiguration();

    for (int i = 0; i < playerConfiguration.numHumanPlayers; i++) {
        model.addPlayer<HumanPlayer>(*view);
    }
    if(playerConfiguration.numAiPlayers > 0) {
        for (int i = 0; i < playerConfiguration.numAiPlayers; i++) {
            int choice = view->getAiChoice();
            if (choice == 1) {
                model.addPlayer<CheatingAI>(*view);
            }else if(choice == 2){
                model.addPlayer<RandomAI>(*view);
            }else if(choice == 3){
                model.addPlayer<HuntDestroyAI>(*view);
            }
        }
    }
    model.SetOpponents();
}

void BattleShip::Controller::setupGame(const std::string &GameConfigurationFile) {
    model.loadGameConfigurationFromFile(GameConfigurationFile);
    setupGame();
}

void BattleShip::Controller::setupGame(const std::string &GameConfigurationFile, int seed) {
    AiPlayer::seed_random_number_generator(seed);
    setupGame(GameConfigurationFile);
}

void BattleShip::Controller::playGame() {
    while (!model.isGameOver()){
        auto attack = model.getNextMove();
        attack->enact(model,*view);
    }
    Player& winner = model.getWinner();
    view->showWinner(winner);
}
