#include "Container.h"
#include "Plant.h"

Node::Node(Plant* newplnt)
{
	plnt = newplnt;
	next = NULL;
	prev = NULL;
}
Container::Container()
{
	Current = NULL;
    Head = NULL;
	length = 0;
}
void Container::In(ifstream& ifst) {
    while (!ifst.eof())
    {
        Node* newNode;
        newNode = new Node((Plant::In(ifst)));
        if (Head == NULL)
        {
            Head = newNode;
            Head->next = newNode;
            Head->prev = newNode;
            length = 1;
        }
        else
        {
            Current = Head;
            while (Current->next != Head)
            {
                Current = Current->next;
            }
            Current->next = newNode;
            Current->next->prev = Current;
            Current = Current->next;
            Current->next = Head;
            Head->prev = Current;



            length++;
        }
    }
}
<<<<<<< Updated upstream

void Container::Clear() {
    Current = NULL;
    Head = NULL;
    length = 0;
};

void Container::Out(ofstream& ofst) {
    ofst << "Container contains " << length << " elements." << endl;

    int i = 1;
    if (Head == NULL) 
    {
        return;
    }
    Sort();
    Current = Head;
    do 
    {
        ofst << i << ": ";
        Current->plnt->Out_Data(ofst);
        OutCountOfLetters(ofst);
        Current = Current->next;
        i++;
    } while (Current != Head);
}

void Container::OutCountOfLetters(ofstream& ofst)
{
    ofst << "count of consonants: " << Current->plnt->CountLetters() << endl;
}

void Container::Sort()
{
    Node* curr1 = Head;
    Node* curr2 = Head;
    do {
        curr2 = curr1->next;
        while (curr2 != Head) {
            if (curr1->plnt->Compare(*curr2->plnt))
            {
                swap(curr1->plnt, curr2->plnt);
            }
            curr2 = curr2->next;
        }
        curr1 = curr1->next;
    } while (curr1 != Head);
=======
void OutCont(ofstream& ofst, Container* c) {
	ofst << "Container contents " << c->length << " elements." << endl;
	int i = 1;
	if (c->Head == NULL)
	{
		return;
	}
	c->Current = c->Head;
	do
	{
		ofst << i << ": ";
		if (c->Current->plnt->key == tree)
		{
			tree_plant* pl;
			pl = (tree_plant*)(c->Current->plnt->obj);
			OutTree(ofst, *pl);
		}
		else
		{
			bush_plant* pn;
			pn = (bush_plant*)(c->Current->plnt->obj);
			OutBush(ofst, *pn);
		}
		c->Current = c->Current->next;
		i++;
	} while (c->Current != c->Head);
>>>>>>> Stashed changes
}