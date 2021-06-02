/*
Linked_list implementation for cracking the code
questions
*/
#include "pch.h"
#include <iostream>
#include <map>

using namespace std;
template <typename dataType>

class List {

private:
	struct Node {
		Node* next;
		dataType data;
	};

public:
	//constructor
	List();

	//destructor
	~List();

	//operations
	bool isEmpty();
	int getLength();
	void Insert(int index, dataType data);
	void Set(int index, dataType data);
	void RemoveAt(int index);
	void crashIfNeeded(int index);
	dataType Get(int index);
	void Print();
	void RemoveAll();
	void Add(dataType data);
	int indexOf(dataType data);

	Node* GetNode(int index);

private:
	int size;
	Node* head;
	Node* tail;
};

/// <summary>deconstructor.
/// <para>cleanup objects.</para>
/// </summary>
template <typename dataType>
List<dataType>::~List() {
	while (!isEmpty())
		RemoveAt(0);
}

/// <summary>constructor.
/// <para>set array count, count and data.</para>
/// </summary>
template <typename dataType>
List<dataType>::List() {
	size = 0;
	head = NULL;
	tail = NULL;
}

/// <summary>
/// Set.
/// <para>Rewrites data by index.</para>
/// </summary>
/// <param name="index">- Index to be rewritten</param>
/// <param name="data">- Data to rewrite</param>
template <typename dataType>
void List<dataType>::Set(int index, dataType data) {
	crashIfNeeded(index);
	//if insert head
	if (index == 0) {
		Node* new_head = new Node;
		new_head->next = head->next;
		new_head->data = data;
		head = new_head;
		if (size == 1)
		{
			tail = head;
		}
	}//if insert into middle
	else {
		Node* prev = GetNode(index - 1);
		Node* node = new Node;
		node->data = data;
		node->next = prev->next->next;
		prev->next = node;
		if (size == index)
		{
			tail = node;
		}
	}
}

/// <summary>
/// Insert.
/// <para>Inserts data by index and push array by 1.</para>
/// </summary>
/// <param name="index">- Index to insert</param>
/// <param name="data">- Data to insert</param>
template <typename dataType>
void List<dataType>::Insert(int index, dataType data) {
	crashIfNeeded(index);
	//if insert head
	if (index == 0) {
		Node* new_head = new Node;
		new_head->next = head;
		new_head->data = data;
		head = new_head;
		if (size == 1)
		{
			tail = head;
		}
	}//if insert into middle
	else {
		Node* prev = GetNode(index - 1);
		Node* node = new Node;
		node->data = data;
		node->next = prev->next;
		prev->next = node;
		if (size == index)
		{
			tail = node;
		}
	}
	size++;
}

/// <summary>
/// Add.
/// <para>Adds elements to array.</para>
/// </summary>
/// <param name="data">- Data to add in array</param>
template<typename dataType>
void List<dataType>::Add(dataType data)
{
	if (this->head == nullptr)
	{
		Node* new_head = new Node;
		new_head->next = head;
		new_head->data = data;
		head = new_head;
		tail = new_head;
	}
	else
	{
		Node* new_node = new Node;
		new_node->data = data;
		new_node->next = nullptr;
		tail->next = new_node;
		tail = new_node;
	}

	size++;
}

/// <summary>
/// indexOf.
/// <para>Searches the specific element.</para>
/// </summary>
/// <param name="data">- Data of the element</param>
template<typename dataType>
int List<dataType>::indexOf(dataType data)
{
	if (this->head == nullptr)
	{
		return -1;
	}
	else
	{
		Node* current = this->head;
		for (int index = 0; current != nullptr; index++)
		{
			if (current->data == data)
			{
				return index;
			}
			current = current->next;
		}
		return -1;
	}
}

/// <summary>
/// RemoveAt.
/// <para>Removes element by index.</para>
/// </summary>
/// <param name="index">- Index to remove data</param>
template <typename dataType>
void List<dataType>::RemoveAt(int index) {
	crashIfNeeded(index);
	Node* cur;
	//if head ptr
	if (index == 0) {
		cur = head;
		head = head->next;
		if (size == 1)
		{
			tail = head;
		}
	}
	else {
		Node* prev = GetNode(index - 1);
		cur = prev->next;
		prev->next = cur->next;
		if (index == size - 1)
		{
			tail = prev;
		}
	}
	cur->next = NULL;
	delete cur;
	cur = NULL;
	size--;
}

/// <summary>
/// RemoveAll.
/// <para>Deletes all data from array.</para>
/// </summary>
template <typename dataType>
void List<dataType>::RemoveAll() {
	while (head != nullptr)
	{
		Node* temp = head;

		head = head->next;

		delete temp;
		size--;
	}
	tail = nullptr;
}

/// <summary>
/// Get.
/// <para>Gets element by its index.</para>
/// </summary>
/// <param name="index">- Index nedded to get</param>
template <typename dataType>
dataType List<dataType>::Get(int index) {
	crashIfNeeded(index);
	Node* cur = GetNode(index);
	return cur->data;
}

/// <summary>
/// GetNode.
/// <para>Returns node by index.</para>
/// </summary>
/// <param name="index">- node index</param>
template <typename dataType>
typename List<dataType>::Node* List<dataType>::GetNode(int index) {
	crashIfNeeded(index);
	Node* cur = head;
	for (int i = 0; i < index; i++) {
		cur = cur->next;
	}
	return cur;
}

/// <summary>
/// Print.
/// <para>Prints the list.</para>
/// </summary>
template <typename dataType>
void List<dataType>::Print() {
	for (Node* cur = head; cur != NULL; cur = cur->next) {
		cout << cur->data << ' ';
	}
	cout << endl;
}

/// <summary>
/// isEmpty.
/// <para>Checks if list is empty.</para>
/// </summary>
template <typename dataType>
bool List<dataType>::isEmpty() {
	return (size == 0) ? true : false;
}

/// <summary>
/// getLength.
/// <para>Shows list's size.</para>
/// </summary>
template <typename dataType>
int List<dataType>::getLength() {
	return size;
}

/// <summary>
/// crashIfNeeded.
/// <para>Crashes the program.</para>
/// </summary>
/// <param name="index">- Index to crash</param>
template<typename dataType>
void List<dataType>::crashIfNeeded(int index) {
	if (index < 0 || index >= size) {
		throw std::out_of_range("index is inivalid");
	}
}
