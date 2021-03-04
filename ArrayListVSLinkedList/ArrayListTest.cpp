
#include "pch.h"
#include <iostream>
#include "ArrayListTest.h"
#include "ArrayList.cpp"

using namespace std;

void ArrayListTest::test() {
	ArrayList<int> myList = ArrayList<int>();

	cout << "ArrayList Test Start." << endl << endl;

	cout << "Adding 16 members.\n\n";

	myList.Add(184387);
	myList.Add(14);
	myList.Add(147);
	myList.Add(1);
	myList.Add(-37);
	myList.Add(584);
	myList.Add(-2147);
	myList.Add(0);
	myList.Add(-75);
	myList.Add(147);
	myList.Add(-37);
	myList.Add(0);
	myList.Add(25);
	myList.Add(187);
	myList.Add(92);
	myList.Add(-17);


	cout << "Printing Added members.\n";
	cout << "The size of the list is: " << myList.Count() << endl;
	cout << myList.toString() << endl;

	cout << "Getting element at 0\n";
	cout << "The element at 0 is: " << myList.Get(0) << endl << endl;

	cout << "Getting element at " << myList.Count() - 1 << endl;
	cout << "The element at " << myList.Count() - 1
		<< " is: " << myList.Get(myList.Count() - 1) << endl << endl;

	cout << "Removing index 22 (out of bounds)\n";

	try {
		myList.Remove(22);
	}
	catch (...) {
		cout << "Expected out of bounds exception\n";
	}

	cout << "The size of the list is: " << myList.Count() << endl;
	cout << myList.toString() << endl;

	cout << "The size of the list is: " << myList.Count() << endl;
	cout << "Removing index 0\n";
	bool removed = myList.Remove(0);
	cout << "Removed status" << removed << endl;
	cout << "The size of the list is: " << myList.Count() << endl;
	cout << myList.toString() << endl;


	cout << "Removing index 5\n";
	myList.Remove(5);
	cout << "The size of the list is: " << myList.Count() << endl;
	cout << myList.toString() << endl;

	cout << "Removing element -2147 (already removed)\n";
	myList.Remove(-2147);
	cout << "The size of the list is: " << myList.Count() << endl;
	cout << myList.toString() << endl;

	cout << "Removing element 14 (already removed)\n";
	myList.Remove(14);
	cout << "The size of the list is: " << myList.Count() << endl;
	cout << myList.toString() << endl;


	cout << "Adding 777 to index 7\n";
	myList.Insert(777, 7);
	cout << " after Add!?\n";
	cout << "The list now contains:\n" << myList.toString() << endl;

	cout << "Adding -9 to index 45 (way out of bounds!)\n";

	try {
		myList.Insert(-9, 45);
	}
	catch (...) {
		cout << "Expected out of bounds exception\n";
	}

	cout << "The list now contains:\n" << myList.toString();
	cout << "As expected the element was not Added at the invalid index!\n\n";

	cout << "Adding 542 to index 7\n";
	myList.Set(542, 7);
	cout << "The list now contains:\n" << myList.toString();

	cout << "ArrayList Test Ending." << endl << endl;
}