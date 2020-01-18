//
// Created by mfbut on 3/11/2019.
//

#include "AttackResult.h"

BattleShip::AttackResult::AttackResult(bool hit, bool destroyed, char shipChar)
    : hit(hit), destroyed(destroyed), shipChar(shipChar) {}
