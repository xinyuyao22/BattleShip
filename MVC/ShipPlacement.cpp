//
// Created by mfbut on 3/10/2019.
//

#include <algorithm>
#include "ShipPlacement.h"

ShipPlacement::ShipPlacement(int rowStart, int colStart, int rowEnd, int colEnd):rowStart(rowStart), colStart(colStart), rowEnd(rowEnd), colEnd(colEnd) {
    normalize();
}

ShipPlacement::ShipPlacement():rowStart(0), colStart(0), rowEnd(0), colEnd(0) {
}

void ShipPlacement::normalize() {
    if(rowStart > rowEnd){
        int tempt = rowStart;
        rowStart = rowEnd;
        rowEnd = tempt;
    }
    if(colStart > colEnd){
        int tempt = colStart;
        colStart = colEnd;
        colEnd = tempt;
    }
}
