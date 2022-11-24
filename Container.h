#pragma once
//#include <iostream>
//#include <fstream>
#include "Plant.h"

using namespace std;

struct Node {
	plant* plnt = NULL;
    Node* next;
    Node* prev;
};

struct Container {
	int length = 0;
	Node* Current = NULL;
	Node* Head = NULL;
};
void Clear(Container* c);
void InCont(ifstream& ifst, Container* c);
void OutCont(ofstream& ofst, Container* c);