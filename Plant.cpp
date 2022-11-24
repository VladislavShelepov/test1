#include "Plant.h"
using namespace std;

plant* InPlant(ifstream& ifst) {
	plant* pt = new plant;
	tree_plant* f;
	bush_plant* a;
	flower_plant* flow;
	int k = 0;
	ifst >> k;
	switch (k) {
	case 1:
		pt->key = tree;
		f = new tree_plant;
		InTree(ifst, *f);
		pt->obj = (void*)f;
		break;
	case 2:
		pt->key = bush;
		a = new bush_plant;
		InBush(ifst, *a);
		pt->obj = (void*)a;
		break;
	case 3:
		pt->key = flower;
		flow = new flower_plant;
		InFlower(ifst, *flow);
		pt->obj = (void*)flow;
		break;
	default:
		return 0;
	}
	return pt;
}