#pragma once
#include <fstream>

using namespace std;

class Plant {
public:
    string name;
    enum place { tundra, desert, steppe, forest };
    place origin;
    static Plant* in(ifstream& ifst);
    virtual void inData(ifstream& ifst) = 0;
    virtual void outData(ofstream& ofst) = 0;
    int countLetters();
    bool compare(Plant& p);
    virtual void outTrees(ofstream& ofst);
//protected:
//    Plant() {};
};