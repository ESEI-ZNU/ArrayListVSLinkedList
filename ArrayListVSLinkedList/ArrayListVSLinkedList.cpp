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

	ArrayList<int> arrayList = ArrayList<int>();
	cout << "ArrayList Test Start." << endl << endl;

	cout << "Adding 20 members.\n\n";

	Timer timer;

	for (int i = 0; i < 2000; i++)
	{
		arrayList.Add(i);
	}

	cout << "Time:" << timer.elapsed() << "\n\n";

	List<int> linkedList;

}
