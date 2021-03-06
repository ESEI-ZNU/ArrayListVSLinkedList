// ArrayListVSLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Dev 3
#include "pch.h"
#include <iostream>
#include <chrono>
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

void getUserInput(int* numberOfLists, int* numberOfItems, int* numberOfRemove) {
    cout << "\t\t\tEnter number of lists to create\n(not recomended to create more than 10,000,000 lists due to long time to create): ";
    cin >> *numberOfLists;
    cout << "\n\t\t\tEnter number of items to create\n(not recomended to create more than 400,000 items due to long time to create): ";
    cin >> *numberOfItems;
    cout << "\n\t\t\tEnter number of items to remove\n(not recomended to remove more than 5,000 items due to long time to remove): ";
    cin >> *numberOfRemove;
    while (*numberOfRemove > *numberOfItems) {
        cout << "\nWrong number.\nEnter number less or equal than " << *numberOfItems << ": ";
        cin >> *numberOfRemove;
    }
}

void compareCreation(int numberOfLists, Timer timer) {
    cout << "\nCreating " << numberOfLists << " instances of array list." << "\n";
    for (int i = 0; i < numberOfLists; i++)
    {
        ArrayList<int> tesrArrayList = ArrayList<int>();
    }
    cout << "Time spent on creating " << numberOfLists << " arrays is: " << timer.elapsed() << "\n\n";

    cout << "Creating " << numberOfLists << " instances of linked list." << "\n";
    timer.reset();
    for (int i = 0; i < numberOfLists; i++)
    {
        List<int> linkedListTest;
    }
    cout << "Time spent on creating " << numberOfLists << " linked lists is: " << timer.elapsed() << "\n\n";
}

void compareAddition(ArrayList<int>* arrayList, List<int>* linkedList, int numberOfItems, Timer timer) {
    timer.reset();

    cout << "Adding " << numberOfItems << " items.\n";
    for (int i = 0; i < numberOfItems; i++)
    {
        (*arrayList).Add(i);
    }
    cout << "Time spent on adding new items is: " << timer.elapsed() << "\n";
    cout << "The size of the array is: " << (*arrayList).Count() << "\n\n";

    cout << "Adding " << numberOfItems << " items.\n";
    timer.reset();
    for (int i = 0; i < numberOfItems; i++)
    {
        (*linkedList).Add(i);
    }
    cout << "Time spent on adding new items is: " << timer.elapsed() << "\n";
    cout << "The size of the linked list is: " << (*linkedList).getLength() << "\n\n";
}

void compareRemoval(ArrayList<int>* arrayList, List<int>* linkedList, int numberOfRemove, Timer timer) {
    cout << "Removing " << numberOfRemove << " indexes from array sized " << (*arrayList).Count() << ". \n";
    timer.reset();
    for (int i = 0; i < numberOfRemove; i++)
    {
        (*arrayList).RemoveAt(i);
    }
    cout << "Time spent on removing indexes is: " << timer.elapsed() << "\n";
    cout << "The size of the array now is: " << (*arrayList).Count() << "\n\n";

    cout << "Removing " << numberOfRemove << " indexes from linked list sized " << (*linkedList).getLength() << ". \n";
    timer.reset();
    for (int i = 0; i < numberOfRemove; i++)
    {
        (*linkedList).RemoveAt(i);
    }
    cout << "Time spent on removing indexes is: " << timer.elapsed() << "\n";
    cout << "The size of the linked list now is: " << (*linkedList).getLength() << "\n\n";
}

void refillLists(ArrayList<int>* arrayList, List<int>* linkedList, int numberOfItems) {
    (*arrayList).Clear();
    (*linkedList).RemoveAll();

    for (int i = 0; i < numberOfItems; i++) {
        (*arrayList).Add(i);
        (*linkedList).Add(i);
    }
}

void compareGets(ArrayList<int>* arrayList, List<int>* linkedList, int numberOfGet, int numberOfItems, Timer timer) {
    while (numberOfGet >= numberOfItems) {
        cout << "\nWrong number.\nEnter number less than " << numberOfItems << ": ";
        cin >> numberOfGet;
    }

    cout << "\nGetting element at " << numberOfGet << " from array sized " << (*arrayList).Count() << ". \n";
    timer.reset();
    cout << "The element is: " << (*arrayList).Get(numberOfGet) << " \n";
    cout << "Time spent on getting element is: " << timer.elapsed() << "\n\n";


    cout << "Getting element at " << numberOfGet << " from linked list sized " << (*linkedList).getLength() << ". \n";
    timer.reset();
    cout << "The element is: " << (*linkedList).Get(numberOfGet) << " \n";
    cout << "Time spent on getting element is: " << timer.elapsed() << "\n\n";
}

void compareSets(ArrayList<int>* arrayList, List<int>* linkedList, int numberOfItems, int setData, int numberOfSet, Timer timer) {
    cout << "\nSetting " << setData << " to indexes from 0 to " << numberOfSet << " to array sized " << (*arrayList).Count() << ". \n";
    timer.reset();
    for (int i = 0; i < numberOfSet; i++)
    {
        (*arrayList).Set(setData, i);
    }
    cout << "Time spent on setting indexes is: " << timer.elapsed() << "\n\n";

    (*arrayList).Clear();
    for (int i = 0; i < numberOfItems; i++)
    {
        (*arrayList).Add(i);
    }

    cout << "Setting " << setData << " to indexes from 0 to " << numberOfSet << " to linked list sized " << (*linkedList).getLength() << ". \n";
    timer.reset();
    for (int i = 0; i < numberOfSet; i++)
    {
        (*linkedList).Set(i, setData);
    }
    cout << "Time spent on setting indexes is: " << timer.elapsed() << "\n\n";

    (*linkedList).RemoveAll();
    for (int i = 0; i < numberOfItems; i++)
    {
        (*linkedList).Add(i);
    }
}

void compareIndexOf(ArrayList<int>* arrayList, List<int>* linkedList, int numberForSearch, Timer timer) {
    cout << "\nSearching the index of " << numberForSearch << " from array sized " << (*arrayList).Count() << ". \n";
    timer.reset();
    cout << "The index of searched element is: " << (*arrayList).IndexOf(numberForSearch) << " \n";
    cout << "Time spent on searching the index is: " << timer.elapsed() << "\n\n";

    cout << "Searching the index of " << numberForSearch << " from linked list sized " << (*linkedList).getLength() << ". \n";
    timer.reset();
    cout << "The index of searched element is: " << (*linkedList).indexOf(numberForSearch) << " \n";
    cout << "Time spent on searching the index is: " << timer.elapsed() << "\n\n";
}

void compareRemoveAll(ArrayList<int>* arrayList, List<int>* linkedList, Timer timer) {
    cout << "Remove all elements from array sized " << (*arrayList).Count() << ". \n";
    timer.reset();
    (*arrayList).Clear();
    cout << "Time spent on removing all elements is: " << timer.elapsed() << "\n\n";

    cout << "Remove all elements from linked list sized " << (*linkedList).getLength() << ". \n";
    timer.reset();
    (*linkedList).RemoveAll();
    cout << "Time spent on removing all elements is: " << timer.elapsed() << "\n\n";
}

int main()
{
    int numberOfLists, numberOfItems, numberOfRemove;

    int numberOfGet, numberOfSet, setData, numberForSearch;

    getUserInput(&numberOfLists, &numberOfItems, &numberOfRemove);

    ArrayList<int> arrayList = ArrayList<int>();
    List<int> linkedList = List<int>();

    Timer timer;

    compareCreation(numberOfLists, timer);

    compareAddition(&arrayList, &linkedList, numberOfItems, timer);

    compareRemoval(&arrayList, &linkedList, numberOfRemove, timer);

    refillLists(&arrayList, &linkedList, numberOfItems);

    cout << "\n\t\t\tEnter number which you want to get\n(choose number from 0 to " << numberOfItems - 1 << "): ";
    cin >> numberOfGet;

    compareGets(&arrayList, &linkedList, numberOfGet, numberOfItems, timer);
    refillLists(&arrayList, &linkedList, numberOfItems);

    cout << "Enter number of items to rewrite\n(not recomended to rewrite more than 30,000 items due to long time to rewrite): ";
    cin >> numberOfSet;
    while (numberOfSet > numberOfItems)
    {
        cout << "\nWrong number.\nEnter number less or equal than " << numberOfItems << ": ";
        cin >> numberOfSet;
    }
    cout << "Enter data to rewrite: ";
    cin >> setData;

    compareSets(&arrayList, &linkedList, numberOfItems, setData, numberOfSet, timer);
    refillLists(&arrayList, &linkedList, numberOfItems);

    cout << "Enter number for search\n(-1 = number not found): ";
    cin >> numberForSearch;

    compareIndexOf(&arrayList, &linkedList, numberForSearch, timer);

    compareRemoveAll(&arrayList, &linkedList, timer);
}
