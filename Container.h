#pragma once
#include <fstream>
#include "Plant.h"
using namespace std;

struct Node 
{
    Plant* plnt;
    Node* next;
    Node* prev;
    Node(Plant* newplant);
};

class Container 
{
    Node* current;
    Node* head;
    int length;
public:
    void in(ifstream& ifst);
    void out(ofstream& ofst);
    void outCountOfLetters(ofstream& ofst);
    void outTrees(ofstream& ofst);
    void clear();
    void sort();
    Container();
    ~Container() { clear(); }
};
bool fileCheck(ifstream& ifst, ofstream& ofst);