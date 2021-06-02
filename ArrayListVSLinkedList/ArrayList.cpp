#include "pch.h"
#include "ArrayList.h"

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

const int minimumArraySize = 2;

/// <summary>constructor.
/// <para>set array count, count and data.</para>
/// </summary>
template<class T>
ArrayList<T>::ArrayList() {
	arraySize = minimumArraySize;
	count = 0;
	data = new T[arraySize];
}

/// <summary>constructor with length.
/// <para>set array count, count and data.</para>
/// <param name="length">- Array size.</param>
/// </summary>
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

/// <summary>deconstructor.
/// <para>cleanup objects.</para>
/// </summary>
template <class T> ArrayList<T> :: ~ArrayList() {
	delete[]data;
};

/// <summary>
/// Get.
/// <para>Gets element by its index.</para>
/// </summary>
/// <param name="index">- Index nedded to get</param>
template <class T> T ArrayList<T> ::Get(int index) {
	crashIfNeeded(index);

	return data[index];
}

/// <summary>
/// Set.
/// <para>Rewrites data by index.</para>
/// </summary>
/// <param name="d">- Data to rewrite</param>
/// <param name="index">- Index to be rewritten</param>
template <class T> void ArrayList<T> ::Set(const T& d, int index) {
	crashIfNeeded(index);

	data[index] = d;
}

/// <summary>
/// IndexOf.
/// <para>Searches the specific element.</para>
/// </summary>
/// <param name="d">- Data of the element</param>
template <class T> int ArrayList<T> ::IndexOf(const T& d) {
	for (int i = 0; i < count; i++) {
		if (data[i] == d) return i;
	}
	return -1;
}

/// <summary>
/// Add.
/// <para>Adds elements to array.</para>
/// </summary>
/// <param name="d">- Data to add in array</param>
template <class T> void ArrayList<T> ::Add(const T& d) {
	if (count >= arraySize) GrowArray();
	data[count++] = d;
}

/// <summary>
/// Insert.
/// <para>Inserts data by index and push array by 1.</para>
/// </summary>
/// <param name="d">- Data to insert</param>
/// <param name="index">- Index to insert</param>
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

/// <summary>
/// Remove.
/// <para>Removes the specific element.</para>
/// </summary>
/// <param name="d">- Data to remove</param>
template <class T> bool ArrayList<T> ::Remove(const T& d) {
	return RemoveAt(IndexOf(d));
}

/// <summary>
/// RemoveAt.
/// <para>Removes element by index.</para>
/// </summary>
/// <param name="index">- Index to remove data</param>
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

/// <summary>
/// Contains.
/// <para>Ñhecks for an element in an array.</para>
/// </summary>
/// <param name="d">- Data to check</param>
template <class T> bool ArrayList<T> ::Contains(const T& d) {
	return IndexOf(d) != -1;
}

/// <summary>
/// Clear.
/// <para>Deletes all data from array.</para>
/// </summary>
template <class T> void ArrayList<T> ::Clear() {
	count = 0;
	arraySize = minimumArraySize;
	delete[]data;
	data = new T[arraySize];
}

/// <summary>
/// GrowArray.
/// <para>Creates a new dynamic array twice the size of the first array.</para>
/// </summary>
template<class T> void ArrayList<T> ::GrowArray() {
	arraySize *= 2;

	T* newData = new T[arraySize];
	for (int i = 0; i < count; i++) {
		newData[i] = data[i];
	}
	delete[]data;
	data = newData;
}

/// <summary>
/// crashIfNeeded.
/// <para>Crashes the program.</para>
/// </summary>
/// <param name="index">- Index to crash</param>
template<class T>
bool ArrayList<T>::crashIfNeeded(int index) {
	if (index < 0 || index >= count) {
		throw std::out_of_range("index is inivalid");
	}
}

/// <summary>
/// toString.
/// <para>Transforms to string.</para>
/// </summary>
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