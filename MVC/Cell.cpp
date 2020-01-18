//
// Created by mfbut on 3/10/2019.
//

#include <stdexcept>
#include "Cell.h"

BattleShip::Cell::Cell(char contents, const char hiddenMarker, const char hitMarker, const char missMarker):contents(contents), firedAt(false), hiddenMarker(hiddenMarker), hitMarker(hitMarker), missMarker(missMarker) {
}

BattleShip::Cell::Cell(char contents):contents(contents), firedAt(false), hiddenMarker('*'), hitMarker('X'), missMarker('O') {
}

char BattleShip::Cell::getContents() const {
    return contents;
}

void BattleShip::Cell::setContents(char contents) {
    Cell::contents = contents;
}

bool BattleShip::Cell::HasBeenFiredAt() const {
    return firedAt;
}

void BattleShip::Cell::setHasBeenFiredAt(bool hasBeenFiredAt) {
    firedAt = hasBeenFiredAt;
}

char BattleShip::Cell::getContentsIfVisible() const {
    return contents;
}

bool BattleShip::Cell::containsShip() const {
    if(contents != hiddenMarker && contents != hitMarker && contents != missMarker){
        return true;
    } else {
        return false;
    }
}

char BattleShip::Cell::getContentsIfHidden() const {
    if(contents == hitMarker || contents == missMarker){
        return contents;
    } else{
        return hiddenMarker;
    }
}

