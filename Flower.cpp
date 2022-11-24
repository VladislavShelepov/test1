#include "Flower.h"
void Flower::inData(ifstream& ifst) 
{
	ifst >> name;
	int typeOfFlower;
	ifst >> typeOfFlower;
	switch (typeOfFlower)
	{
	case 1:
		type = domestic;
		break;
	case 2:
		type = garden;
		break;
	case 3:
		type = wild;
		break;
	}
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

void Flower::outData(ofstream& ofst) 
{
	ofst << "Name: " << name << endl;
	switch (type)
	{
	case 0:
		ofst << "It is a flower. It's domestic." << endl;
		break;
	case 1:
		ofst << "It is a flower. It's garden." << endl;
		break;
	case 2:
		ofst << "It is a flower. It's wild." << endl;
		break;
	}
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
void Flower::outTrees(ofstream& ofst)
{
	ofst << endl;
}