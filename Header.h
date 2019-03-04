#include <stdio.h>


struct Node //Struct Node for class List with val and pointer on the previous element
{
	int val;
	Node*prev;
	Node(int value)
	{
		val = value;
		prev = NULL;
	}
};


class List //Class List with the two pointers: on the head and on the tail;
{
public:
	Node * head;
	Node*tail;
	List()
	{
		head = NULL;
		tail = NULL;
	}
};


class Stack
{
public:
	List * list;
	int stacksize; //numbers of elements in the stack


	Stack()
	{
		list = new List();
		stacksize = 0;
	}

	int size()
	{
		return stacksize;
	}

	int pop() //deleting top element from the stack
	{
		if (list->head == NULL) return -1;
		int value = list->head->val;
		list->head = list->head->prev;
		--stacksize;
		return value;
	}

	void push(int val) // adding element on  top of the stack
	{
		Node*node = new Node(val);
		if (list->head == NULL)
		{
			list->head = node;
			node->prev = NULL;
		}
		else {
			node->prev = list->head;
			list->head = node;
		}
		++stacksize;
	}

	int peek() // returning value of the stack's top element
	{
		if (list->head != NULL)
		{
			return list->head->val;
		}
		else
			return -1;
	}
};

