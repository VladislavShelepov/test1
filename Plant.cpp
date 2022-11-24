#include "Plant.h"
#include "Tree.h"
#include "Bush.h"
#include "Flower.h"

Plant* Plant::in(ifstream& ifst) 
{
    Plant* pt;
    int typeOfPlant;
    ifst >> typeOfPlant;
    if (typeOfPlant == 1)
    {
        pt = new Tree;
    }
    else if (typeOfPlant == 2)
    {
        pt = new Bush;
    }
    else if (typeOfPlant == 3)
    {
        pt = new Flower;
    }
    else
    {
        return 0;
    }
    pt->inData(ifst);
    return pt;
}

bool Plant::compare(Plant& p)
{
    return countLetters() < p.countLetters();
}

void Plant::outTrees(ofstream& ofst)
{
    ofst << endl;
}

int Plant::countLetters() {
    string LETTERS = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";
    int cnt = 0;
    for (int i = 0; i < name.length(); i++)
    {
        if (LETTERS.find(name[i]) < LETTERS.length())cnt++;
    }
    return cnt;
}