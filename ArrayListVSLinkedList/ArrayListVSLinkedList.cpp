// ArrayListVSLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Dev 3

#include "pch.h"
#include <iostream>
#include <chrono>
#include "ArrayListTest.h"
#include "ArrayList.cpp"
#include "LinkedList.cpp"

using namespace std;

//--------------------------TIMER--------------------------//
class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};
//--------------------------TIMER-END--------------------------//


int main()
{
	cout << "ArrayList Start." << "\n\n";
	ArrayList<int> arrayList = ArrayList<int>();

	cout << "Creating 10,000,000 lists." << "\n";
	Timer timer;
	for (int i = 0; i < 10000000; i++)
	{
		ArrayList<int> tesrArrayList = ArrayList<int>();
	}
	cout << "Time spent on creating 10,000,000 lists is: " << timer.elapsed() << "\n\n";

	cout << "Adding 100,000,000 members.\n";
	timer.reset();
	for (int i = 0; i < 100000000; i++)
	{
		arrayList.Add(i);
	}
	cout << "Time spent on adding new elements is:" << timer.elapsed() << "\n";
	cout << "The size of the list is: " << arrayList.Count() << "\n\n";

	arrayList.Clear();
	for (int i = 0; i < 100000; i++)
	{
		arrayList.Add(i);
	}

	cout << "Removing 10,000 indexes from array sized " << arrayList.Count() << ". \n";
	timer.reset();
	for (int i = 0; i < 10000; i++)
	{
		arrayList.RemoveAt(i);
	}
	cout << "Time spent on removing indexes is:" << timer.elapsed() << "\n";
	cout << "The size of the list now is: " << arrayList.Count() << "\n\n";
	
	arrayList.Clear();
	for (int i = 0; i < 10000000; i++)
	{
		arrayList.Add(i);
	}

	cout << "Getting element at 1,000,000 from array sized " << arrayList.Count() << ". \n";
	timer.reset();
	cout << "The element at 1,000,000 is: " << arrayList.Get(1000000) << " \n";
	cout << "Time spent on getting element is: " << timer.elapsed() << "\n\n";
	
	arrayList.Clear();
	for (int i = 0; i < 1000000; i++)
	{
		arrayList.Add(i);
	}

	cout << "Setting 5555 to indexes from 0 to array sized " << arrayList.Count() << ". \n";
	timer.reset();
	for (int i = 0; i < 1000000; i++)
	{
		arrayList.Set(5555, i);
	}
	cout << "Time spent on setting indexes is: " << timer.elapsed() << "\n\n";
	
	arrayList.Clear();
	for (int i = 0; i < 10000000; i++)
	{
		arrayList.Add(i);
	}

	cout << "Searching the index of 1000000 from array sized " << arrayList.Count() << ". \n";
	timer.reset();
	cout << "The index of searched element is: " << arrayList.IndexOf(1000000) << " \n";
	cout << "Time spent on searching the index is: " << timer.elapsed() << "\n\n";

	cout << "Remove all elements from array sized " << arrayList.Count() << ". \n";
	timer.reset();
	arrayList.Clear();
	cout << "Time spent on removing all elements is: " << timer.elapsed() << "\n\n";

	cout << "ArrayList End." << "\n\n";

	List<int> linkedList;

}