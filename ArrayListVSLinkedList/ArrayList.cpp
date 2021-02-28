#include "pch.h"
#include <iostream>

using namespace std;

//Dev 1

template<typename T>
class ArrayList
{
	T _items[];
	
	public:           
		ArrayList() {
			return this(0);
		}

	public:
		ArrayList(int length)
		{
		if (length < 0)
		{
			//throw new ArgumentException("length");
		}

		_items = new T[length];
		}

	/* 
	public int IndexOf(T item)
	{
		throw new NotImplementedException();
	}

	public void Insert(int index, T item)
	{
		throw new NotImplementedException();
	}

	public void RemoveAt(int index)
	{
		throw new NotImplementedException();
	}

	public T this[int index]
	{
		get
		{
			throw new NotImplementedException();
		}
		set
		{
			throw new NotImplementedException();
		}
	}

	public void Add(T item)
	{
		throw new NotImplementedException();
	}

	public void Clear()
	{
		throw new NotImplementedException();
	}

	public bool Contains(T item)
	{
		throw new NotImplementedException();
	}

	public void CopyTo(T[] array, int arrayIndex)
	{
		throw new NotImplementedException();
	}

	public int Count
	{
		get { throw new NotImplementedException(); }
	}

	public bool IsReadOnly
	{
		get { throw new NotImplementedException(); }
	}

	public bool Remove(T item)
	{
		throw new NotImplementedException();
	}

	public System.Collections.Generic.IEnumerator GetEnumerator()
	{
		throw new NotImplementedException();
	}

	System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
	{
		throw new NotImplementedException();
	}
	*/
};