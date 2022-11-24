#include "Bush.h"
void Bush::inData(ifstream& ifst) {
    ifst >> name;
	int mounthOfBlossom, originOfPlant;
	ifst >> mounthOfBlossom;
	switch (mounthOfBlossom)
	{
	case 1:
		blossom = January;
		break;
	case 2:
		blossom = February;
		break;
	case 3:
		blossom = March;
		break;
	case 4:
		blossom = April;
		break;
	case 5:
		blossom = May;
		break;
	case 6:
		blossom = June;
		break;
	case 7:
		blossom = July;
		break;
	case 8:
		blossom = August;
		break;
	case 9:
		blossom = September;
		break;
	case 10:
		blossom = October;
		break;
	case 11:
		blossom = November;
		break;
	case 12:
		blossom = December;
		break;
	}
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

void Bush::outData(ofstream& ofst) {
	ofst << "Name: " << name << endl;
	switch (blossom)
	{
	case 0:
		ofst << "It is a bush. It's flowering month is January." << endl;
		break;
	case 1:
		ofst << "It is a bush. It's flowering month is February." << endl;
		break;
	case 2:
		ofst << "It is a bush. It's flowering month is March." << endl;
		break;
	case 3:
		ofst << "It is a bush. It's flowering month is April." << endl;
		break;
	case 4:
		ofst << "It is a bush. It's flowering month is May." << endl;
		break;
	case 5:
		ofst << "It is a bush. It's flowering month is June." << endl;
		break;
	case 6:
		ofst << "It is a bush. It's flowering month is July." << endl;
		break;
	case 7:
		ofst << "It is a bush. It's flowering month is August." << endl;
		break;
	case 8:
		ofst << "It is a bush. It's flowering month is September." << endl;
		break;
	case 9:
		ofst << "It is a bush. It's flowering month is October." << endl;
		break;
	case 10:
		ofst << "It is a bush. It's flowering month is November." << endl;
		break;
	case 11:
		ofst << "It is a bush. It's flowering month is December." << endl;
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
void Bush::outTrees(ofstream& ofst)
{
	ofst << endl;
}
