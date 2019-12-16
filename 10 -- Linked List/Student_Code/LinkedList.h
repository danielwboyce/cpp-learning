#include "LinkedListInterface.h"
#include <stdexcept>
using namespace std;

template<class T>
class LinkedList : public LinkedListInterface<T>
{
public:

	LinkedList()
	{
		head = NULL;
		tail = NULL;
		current = NULL;
		no_of_nodes_in_list = 0;
	}
	~LinkedList(){}

	/*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	void insertHead(T value)
	{
		if (this->duplicateChecker(value) == -1)
		{
			Node* onepointer = new Node(value);
			onepointer->next = head;
			head = onepointer;
			no_of_nodes_in_list++;
		}
		else
		{
			return;
		}
	}

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	void insertTail(T value)
	{
		if (this->duplicateChecker(value) == -1)
		{
			this->iteratorToValue(value);
			tail = current;
			Node* onepointer = new Node(value);
			tail->next = onepointer;
			no_of_nodes_in_list++;
		}
		else
		{
			return;
		}
	}

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	void insertAfter(T value, T insertionNode)
	{
		int index = this->duplicateChecker(insertionNode);
		if (index == -1)
		{
			return;
		}
		else
		{
			this->iteratorToValue(insertionNode);
			Node* onepointer = new Node(value);
			onepointer->next = current->next;
			current->next = onepointer;
			no_of_nodes_in_list++;
		}
	}

	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	void remove(T value)
	{
		return;
	}

	/*
	clear

	Remove all nodes from the list.
	*/
	void clear()
	{
		return;
	}

	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	T at(int index)
	{
		if (index >= this->size())
		{
			throw std::out_of_range("message");
		}
		else
		{
			current = head;
			for (int i = 0; i < index; i++)
			{
				current = current->next;
			}
			return current->value;
		}
	}

	/*
	size

	Returns the number of nodes in the list.
	*/
	int size()
	{
		return no_of_nodes_in_list;
	}

private:
	struct Node
	{
		Node(T value_in)
		{
			value = value_in;
			next = NULL;
		}
		~Node(){}

		T value;
		Node* next;
	};

	Node* head;
	Node* tail;
	Node* current;
	int no_of_nodes_in_list;

	//This function will search through the list to see if there's a duplicate entry in the list
	int duplicateChecker(T value_in)
	{
		current = head;
		int current_index = 0;
		if (head->next == NULL || current_index >= this->size())
		{
			return -1;
		}
		else if (current->value == value_in)
		{
			return current_index;
		}
		else
		{
			current = current->next;
			current_index++;
		}
	}

	//Iterates the current pointer to point at the node that holds value_in, if there is no such node it iterates the current pointer to point at the tail
	void iteratorToValue(T value_in)
	{
		current = head;
		if (current->next == NULL)
		{
			return;
		}
		else if (current->value == value_in)
		{
			return;
		}
		else
		{
			current = current->next;
		}
	}

};