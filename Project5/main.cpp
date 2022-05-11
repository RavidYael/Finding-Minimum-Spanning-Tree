//
// Created by Dan Schindler on 10/05/2022.
//

#include <iostream>
#include "Communicator.h"
#include "Logic.h"

using namespace std;

    void main(int argc, char* argv[]) {
        Logic engine;
        Communicator fileHandler(argv[1]);
        engine.buildGraphFromEdgeDataArray(fileHandler.ReadGraphDetailsFromFile());
    }
