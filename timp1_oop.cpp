#include <iostream>
#include <fstream>
using namespace std;
#include "Container.h"

int main(int argc, char* argv[])
{
    if (argc != 3) {
        cout << "incorrect command line! "
            "Waited: command in_file out_file"
            << endl;
        exit(1);
    }

    ifstream ifst(argv[1]);
    ofstream ofst(argv[2]);
    cout << "Start" << endl;   

    fileCheck(ifst, ofst);

    ifst.close();
    ifst.open(argv[1]);
    Container c;

    c.in(ifst);
    ofst << "Filled container. " << endl;
    c.out(ofst);
    c.sort();
    ofst << endl;
    ofst << "Container sorted. " << endl;
    c.out(ofst);
    ofst << "Only Trees: " << endl;
    c.outTrees(ofst);
    c.clear();
    ofst << "Empty container. " << endl;
    c.out(ofst);

    cout << "Stop" << endl;
    system("pause");
    return 0;
}