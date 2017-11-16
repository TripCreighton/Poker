//
//  Serializer.hpp
//  Poker
//
//  Created by Trip Creighton on 11/1/17.
//  Copyright © 2017 Trip Creighton. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Serializer {
private:
    string _fileDirectory;
public:
    Serializer();
    string getWorkingDirectory();
};
