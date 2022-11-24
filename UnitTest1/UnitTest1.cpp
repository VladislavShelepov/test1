#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Shele\Documents\GitHub\Timp_oop\Container.cpp"
#include "C:\Users\Shele\Documents\GitHub\Timp_oop\Flower.cpp"
#include "C:\Users\Shele\Documents\GitHub\Timp_oop\Plant.cpp"
#include "C:\Users\Shele\Documents\GitHub\Timp_oop\Tree.cpp"
#include "C:\Users\Shele\Documents\GitHub\Timp_oop\Bush.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(Tests)
	{
	public:
	TEST_METHOD(TestCountLetters)
	{
		ifstream ifst("C:/Users/Shele/Documents/GitHub/Timp_oop/UnitTest1/testCountLetters.txt");
		Plant* pl = Plant::in(ifst);

		int res = pl->countLetters();
		int exp = 5;
		Assert::AreEqual(exp, res);
	}
	TEST_METHOD(TestCompare)
	{
		ifstream ifst("C:/Users/Shele/Documents/GitHub/Timp_oop/UnitTest1/testCountLetters.txt");
		Plant* pl1, * pl2;
		pl1 = new Tree;
		pl2 = new Tree;

		pl1->in(ifst);
		pl2->in(ifst);
		Node* n1, * n2;
		n1 = new Node(pl1);
		n2 = new Node(pl2);
		bool res = n1->plnt->compare(*n2->plnt);
		bool exp = false;
		Assert::AreEqual(exp, res);
	}

	TEST_METHOD(TestInOut)
	{
		ifstream ifst("C:/Users/Shele/Documents/GitHub/Timp_oop/UnitTest1/inTest.txt");
		ofstream ofst("C:/Users/Shele/Documents/GitHub/Timp_oop/UnitTest1/expTestIn.txt");

		Tree* t = new Tree;
		Bush* b = new Bush;
		Flower* f = new Flower;

		t->inData(ifst);
		b->inData(ifst);
		f->inData(ifst);

		t->outData(ofst);
		b->outData(ofst);
		f->outData(ofst);

		ifstream ifst1("C:/Users/Shele/Documents/GitHub/Timp_oop/UnitTest1/expInTest.txt");
		ifstream ifst2("C:/Users/Shele/Documents/GitHub/Timp_oop/UnitTest1/expTestIn.txt");
		char c1, c2;
		while (ifst1.get(c1) && ifst2.get(c2))
		{
			Assert::AreEqual(c1, c2);
		}
	}

	TEST_METHOD(TestInputOutput)
	{
		ifstream ifst;
		ifst.open("C:/Users/Shele/Documents/GitHub/Timp_oop/UnitTest1/inputTest.txt");
		ofstream ofst;
		ofst.open("C:/Users/Shele/Documents/GitHub/Timp_oop/UnitTest1/outputTest.txt");
		Container c;

		bool res = true;
		bool exp = true;

		c.in(ifst);
		c.out(ofst);

		ifstream ifst1("C:/Users/Shele/Documents/GitHub/Timp_oop/UnitTest1/expOutputTest.txt");
		ifstream ifst2("C:/Users/Shele/Documents/GitHub/Timp_oop/UnitTest1/outputTest.txt");
		char c1, c2;
		while (ifst1.get(c1) && ifst2.get(c2))
		{
			Assert::AreEqual(c1, c2);
		}
	}
	TEST_METHOD(TestClear)
	{
		ifstream ifst;
		ifst.open("C:/Users/Shele/Documents/GitHub/Timp_oop/UnitTest1/inputTest.txt");
		ofstream ofst;
		ofst.open("C:/Users/Shele/Documents/GitHub/Timp_oop/UnitTest1/clearTest.txt");
		Container c;

		bool res = true;
		bool exp = true;

		c.in(ifst);
		c.clear();
		c.out(ofst);


		ifstream ifst1("C:/Users/Shele/Documents/GitHub/Timp_oop/UnitTest1/clearTest.txt");
		ifstream ifst2("C:/Users/Shele/Documents/GitHub/Timp_oop/UnitTest1/expClearTest.txt");
		char c1, c2;
		while (ifst1.get(c1) && ifst2.get(c2))
		{
			Assert::AreEqual(c1, c2);
		}
	}
	TEST_METHOD(TestSort)
	{
		ifstream ifst;
		ifst.open("C:/Users/Shele/Documents/GitHub/Timp_oop/UnitTest1/sortTest.txt");
		ofstream ofst;
		ofst.open("C:/Users/Shele/Documents/GitHub/Timp_oop/UnitTest1/outSortTest.txt");
		Container c;


		c.in(ifst);
		c.sort();
		c.out(ofst);

		ifstream ifst1("C:/Users/Shele/Documents/GitHub/Timp_oop/UnitTest1/outSortTest.txt");
		ifstream ifst2("C:/Users/Shele/Documents/GitHub/Timp_oop/UnitTest1/expOutSortTest.txt");
		char c1 = ' ', c2 = ' ';
		while (ifst1.get(c1) && ifst2.get(c2))
		{
			Assert::AreEqual(c1, c2);
		}
	}
	TEST_METHOD(TestOutTrees)
	{
		ifstream ifst;
		ifst.open("C:/Users/Shele/Documents/GitHub/Timp_oop/UnitTest1/treesTest.txt");
		ofstream ofst;
		ofst.open("C:/Users/Shele/Documents/GitHub/Timp_oop/UnitTest1/outTreesTest.txt");
		Container c;

		bool res = true;
		bool exp = true;

		c.in(ifst);
		c.outTrees(ofst);

		ifstream ifst1("C:/Users/Shele/Documents/GitHub/Timp_oop/UnitTest1/outTreesTest.txt");
		ifstream ifst2("C:/Users/Shele/Documents/GitHub/Timp_oop/UnitTest1/expOutTreesTest.txt");
		char c1, c2;
		while (ifst1.get(c1) && ifst2.get(c2))
		{
			Assert::AreEqual(c1, c2);
		}
	}
	};
}