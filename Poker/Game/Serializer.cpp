//
//  Serializer.cpp
//  Poker
//
//  Created by Trip Creighton on 11/1/17.
//  Copyright © 2017 Trip Creighton. All rights reserved.
//

#include "Serializer.hpp"

Serializer::Serializer() {
    this->_fileDirectory = getWorkingDirectory() +  "/serialized.txt";
    std::cout << _fileDirectory << std::endl;
}

string Serializer::getWorkingDirectory() {
    return "";
}

