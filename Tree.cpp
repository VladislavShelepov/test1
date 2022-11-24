#include  "Tree.h"

void Tree::inData(ifstream& ifst) 
{
    ifst >> name;
    ifst >> age;
    int originOfPlant;
    ifst >> originOfPlant;
    switch (originOfPlant)
    {
	case 1:
		origin = tundra;
		break;
	case 2:
		origin = desert;
		break;
	case 3:
		origin = steppe;
		break;
	case 4:
		origin = forest;
		break;
    }
}
void Tree::outData(ofstream& ofst) 
{
    ofst << "Name: " << name << endl;
    ofst << "It is a tree. It's age is " << age << " days." << endl;
	switch (origin)
	{
	case 0:
		ofst << "It grows in tundra." << endl;
		break;
	case 1:
		ofst << "It grows in desert." << endl;
		break;
	case 2:
		ofst << "It grows in steppe." << endl;
		break;
	case 3:
		ofst << "It grows in forest." << endl;
		break;
	}
}

void Tree::outTrees(ofstream& ofst)
{
    outData(ofst);
}