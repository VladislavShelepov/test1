#include "Container.h"
#include "Plant.h"
#include <iostream>
#include <string>

Node::Node(Plant* newplnt)
{
	plnt = newplnt;
	next = NULL;
	prev = NULL;
}

Container::Container()
{
	current = NULL;
    head = NULL;
	length = 0;
}

void Container::in(ifstream& ifst) 
{
    while (!ifst.eof())
    {
        Node* newNode;
        newNode = new Node((Plant::in(ifst)));
        if (head == NULL)
        {
            head = newNode;
            head->next = newNode;
            head->prev = newNode;
            length = 1;
        }
        else
        {
            current = head;
            while (current->next != head)
            {
                current = current->next;
            }
            current->next = newNode;
            current->next->prev = current;
            current = current->next;
            current->next = head;
            head->prev = current;
            length++;
        }
    }
}

void Container::clear() 
{
    current = NULL;
    head = NULL;
    length = 0;
}

void Container::out(ofstream& ofst) 
{
    ofst << "Container contains " << length << " elements." << endl;

    int i = 1;
    if (head == NULL) 
    {
        return;
    }
    current = head;
    do 
    {
        ofst << i << ": ";
        current->plnt->outData(ofst);
        outCountOfLetters(ofst);
        current = current->next;
        i++;
    } while (current != head);
}

void Container::outCountOfLetters(ofstream& ofst)
{
    ofst << "count of consonants: " << current->plnt->countLetters() << endl;
}

void Container::sort()
{
    Node* curr1 = head;
    Node* curr2 = head;
    do
	{
        curr2 = curr1->next;
        while (curr2 != head) {
            if (curr1->plnt->compare(*curr2->plnt))
            {
                swap(curr1->plnt, curr2->plnt);
            }
            curr2 = curr2->next;
        }
        curr1 = curr1->next;
    } while (curr1 != head);
}
void Container::outTrees(ofstream& ofst) 
{
    int i = 1;
    if (head == NULL)
    {
        return;
    }
    current = head;
    do
    {
        ofst << i << ": ";
        if (current->plnt)current->plnt->outTrees(ofst);
        current = current->next;
        i++;
    } while (current != head);
}
bool fileCheck(ifstream& ifst, ofstream& ofst)
{
	bool result = true;
	string DIGITS = "0123456789";
	char tmpChar[100];
	string tmpStr;


	if (!ifst.is_open())
	{
		cout << "Input file was not found.";
		exit(1);
	}
	if (!ofst.is_open())
	{
		cout << "Output file was not found.";
		exit(1);
	}
	int cnt = 1;

	while (!ifst.eof())//type check
	{
		ifst.getline(tmpChar, 100, '\n');
		tmpStr = (tmpChar);
		if (tmpStr == "")
		{
			cout << cnt << " Error: Type is a blank string.\n";
			result = false;
			exit(1);
		}
		for (int i = 0; i < tmpStr.length(); i++)
		{
			if (!(DIGITS.find(tmpStr[i]) < DIGITS.length()))
			{
				cout << cnt << " Error: Type definition contains incorrect characters.\n";
				result = false;
				exit(1);
			}
		}
		int kind = std::stoi(tmpStr);
		if (kind <= 0 || kind > 3)
		{
			cout << cnt << " Error: Type is out of range.\n";
			result = false;
			exit(1);
		}

		ifst.getline(tmpChar, 100, '\n');//name
		tmpStr = (tmpChar);
		if (tmpStr == "")
		{
			cout << cnt << " Error: Name of the plant is a blank string.\n";
			result = false;
			exit(1);
		}
		
		switch (kind)//for different types
		{
		case 1:
		{
			ifst.getline(tmpChar, 100, '\n');//tree - age
			tmpStr = (tmpChar);
			if (tmpStr == "")
			{
				cout << cnt << " Error: The tree's age is a blank string.\n";
				result = false;
				exit(1);
			}
			for (int i = 0; i < tmpStr.length(); i++)
			{
				if (!(DIGITS.find(tmpStr[i]) < DIGITS.length()))
				{
					cout << cnt << " Error: The tree's age contains incorrect characters.\n";
					result = false;
					exit(1);
				}
			}
			int age = std::stoi(tmpStr);
			if (age <= 0)
			{
				cout << cnt << " Error: The tree's age is out of range.\n";
				result = false;
				exit(1);
			}
			break;
		}
		case 2:
		{
			ifst.getline(tmpChar, 100, '\n');//bush - blossom
			tmpStr = (tmpChar);
			if (tmpStr == "")
			{
				cout << cnt << " Error: The flowering month is a blank string.\n";
				result = false;
				exit(1);
			}
			for (int i = 0; i < tmpStr.length(); i++)
			{
				if (!(DIGITS.find(tmpStr[i]) < DIGITS.length()))
				{
					cout << cnt << " Error: The flowering month contains incorrect characters.\n";
					result = false;
					exit(1);
				}
			}
			int kind = std::stoi(tmpStr);
			if (kind <= 0 || kind > 12)
			{
				cout << cnt << " Error: The flowering month is out of range.\n";
				result = false;
				exit(1);
			}
			break;
		}
		case 3:
		{
			ifst.getline(tmpChar, 100, '\n');// flower - type
			tmpStr = (tmpChar);
			if (tmpStr == "")
			{
				cout << cnt << " Error: The flower's type is a blank string.\n";
				result = false;
				exit(1);
			}
			for (int i = 0; i < tmpStr.length(); i++)
			{
				if (!(DIGITS.find(tmpStr[i]) < DIGITS.length()))
				{
					cout << cnt << " Error: The flower's type contains incorrect characters.\n";
					result = false;
					exit(1);
				}
			}
			int kind = std::stoi(tmpStr);
			if (kind <= 0 || kind > 3)
			{
				cout << cnt << " Error: The flower's type is out of range.\n";
				result = false;
				exit(1);
			}
			break;
		}
		}
		
		ifst.getline(tmpChar, 100, '\n');//origin
		tmpStr = (tmpChar);
		if (tmpStr == "")
		{
			cout << cnt << " Error: The origin is a blank string.\n";
			result = false;
			exit(1);
		}
		for (int i = 0; i < tmpStr.length(); i++)
		{
			if (!(DIGITS.find(tmpStr[i]) < DIGITS.length()))
			{
				cout << cnt << " Error: The origin contains incorrect characters.\n";
				result = false;
				exit(1);
			}
		}
		int origin = std::stoi(tmpStr);
		if (origin <= 0 || origin > 4)
		{
			cout << cnt << " Error: The origin is out of range.\n";
			result = false;
			exit(1);
		}
		//
		cnt++;
	}
	return result;
}