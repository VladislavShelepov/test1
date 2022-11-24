#pragma once
#include "Plant.h"
#include <fstream>
using namespace std;

class Tree : public Plant 
{
    long age;
public:
    void inData(ifstream& ifst);
    void outData(ofstream& ofst);
    void outTrees(ofstream& ofst);
    Tree() {};
};