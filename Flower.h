#pragma once
#include "Plant.h"
#include <fstream>
using namespace std;

class Flower : public Plant {

    enum kind { domestic, garden, wild };
    kind type;

public:
    void inData(ifstream& ifst);
    void outData(ofstream& ofst);
    void outTrees(ofstream& ofst);
    Flower() {};
};