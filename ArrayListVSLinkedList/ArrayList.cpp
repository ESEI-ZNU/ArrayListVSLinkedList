#include "pch.h"
#include "ArrayList.h"

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

const int minimumArraySize = 2;

//constructor
//set array count, count and data
template<class T>
ArrayList<T>::ArrayList() {
	arraySize = minimumArraySize;
	count = 0;
	data = new T[arraySize];
}

//constructor with length
//set array count, count and data
template<class T>
ArrayList<T>::ArrayList(int length) {
	if (length < 0)
	{
		throw std::invalid_argument("Length should be grater than 0");
	}
	arraySize = length;
	count = 0;
	data = new T[arraySize];
}

//deconstructor
//cleanup objects
template <class T> ArrayList<T> :: ~ArrayList() {
	delete[]data;
};


template <class T> T ArrayList<T> ::Get(int index) {
	crashIfNeeded(index);

	return data[index];
}

template <class T> void ArrayList<T> ::Set(const T& d, int index) {
	crashIfNeeded(index);

	data[index] = d;
}

template <class T> int ArrayList<T> ::IndexOf(const T& d) {
	for (int i = 0; i < count; i++) {
		if (data[i] == d) return i;
	}
	return -1;
}

template <class T> void ArrayList<T> ::Add(const T& d) {
	if (count >= arraySize) GrowArray();
	data[count++] = d;
}

template <class T> void ArrayList<T> ::Insert(const T& d, int index) {
	if (count >= arraySize) GrowArray();
	//accept index at count
	if (!(index >= 0 && index <= count)) return;
	//move all obj's at >= index up 1
	for (int i = count - 1; i >= 0; i--) {
		if (i >= index) {
			data[i + 1] = data[i];
		}
	}
	data[index] = d;
	count++;
}

template <class T> bool ArrayList<T> ::Remove(const T& d) {
	return RemoveAt(IndexOf(d));
}


template <class T> bool ArrayList<T> ::RemoveAt(int index) {
	if (index < 0 || index >= count) {
		return false;
	}
	//shift elements down
	for (int i = index + 1; i < count - 1; i++) {
		data[i - 1] = data[i];
	}

	//adjust size
	count--;
	//remove last element
	data[count] = NULL;
	return true;
}

template <class T> bool ArrayList<T> ::Contains(const T& d) {
	return IndexOf(d) != -1;
}

template <class T> void ArrayList<T> ::Clear() {
	count = 0;
	arraySize = minimumArraySize;
	delete[]data;
	data = new T[arraySize];
}

template<class T> void ArrayList<T> ::GrowArray() {
	arraySize *= 2;

	T* newData = new T[arraySize];
	for (int i = 0; i < count; i++) {
		newData[i] = data[i];
	}
	delete[]data;
	data = newData;
}

template<class T>
bool ArrayList<T>::crashIfNeeded(int index) {
	if (index < 0 || index >= count) {
		throw std::out_of_range("index is inivalid");
	}
}

template<class T>
std::string ArrayList<T>::toString() {

	std::ostringstream streamOut;

	streamOut << "(";

	for (int i = 0; i < count; i++) {

		streamOut << data[i];

		if (i != (count - 1)) {

			streamOut << ", ";
		}
	}

	streamOut << ")\n";

	std::string returnString = streamOut.str();

	return returnString;
}