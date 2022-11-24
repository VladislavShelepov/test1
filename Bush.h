#pragma once
#pragma once
#include "Plant.h"
#include <fstream>
using namespace std;

class Bush : public Plant 
{
    enum month { January, February, March, April, May, June, July, August, September, October, November, December };
    month blossom;
public:
    void inData(ifstream& ifst);
    void outData(ofstream& ofst);
    void outTrees(ofstream& ofst);
    Bush() {};
};