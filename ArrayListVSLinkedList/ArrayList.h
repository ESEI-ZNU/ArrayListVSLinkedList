#include "pch.h"

#include <string>
#include <iostream>

#pragma once
template <class T> class ArrayList {

public:
	// Constructor to initialize the list.
	ArrayList();

	ArrayList(int length);

	// Destructor to clean up the list.
	~ArrayList();

	// Finds a specifies element of the array list based on the index. Returns null if nothing.
	T Get(int index);

	//Finds the index of the given element.
	int IndexOf(const T &d);

	// Inserts an element at the end of the list.
	void Add(const T &d);

	// Inserts an element at a specified position in the array list.
	void Insert(const T &d, int position);

	// Deletes the element at the given index.
	// TRUE if successful
	bool RemoveAt(int index);

	// Remove the given element
	bool Remove(const T &d);

	// TRUE if this array contains the given data
	bool Contains(const T &d);

	// Empties/clears out the array list structure.
	void Clear();

	// Returns the size of the array.
	inline int Count() { return count; }

	// For testing purposes
	std::string toString();

	//Part of c# IList<T> interface: not needed since we use c++ :)
	//CopyTo
	//IsReadOnly
	//GetEnumerator()

private:

	int arraySize;// Size of the array.
	int count; // Number of elements in the array.
	T *data = nullptr;// Pointer to the array.

	//makes space in the array by doubling the arraySize
	void GrowArray();

	//crash if index is out of range (0 -> size)
	bool crashIfNeeded(int index);
};