#include"Header.h"
class Queue
{
public:
	Stack * stack1;
	Stack*stack2;
	int queuesize;
	Queue()
	{
		stack1 = new Stack();
		stack2 = new Stack();
		queuesize = 0;
	}

	void enqueue(int item)
	{
		stack1->push(item);
	}

	int dequeue()
	{
		while(stack1->size()!=0)
		{
			stack2->push(stack1->pop());
		}
		if (stack2->size() == 0) return -1;
		return stack2->pop();
	}

	int size()
	{
		return queuesize;
	}
	
	void rotate(int N)
	{
		for (int i = 0; i < N; ++i)
		{
			enqueue(dequeue());
		}
	}

};

int main()
{
	Queue*queue = new Queue();
	for (int i = 0; i < 10; i++)
	{
		queue->enqueue(i);
	}

	printf("%i\n", queue->dequeue());
	printf("%i\n", queue->dequeue());

}
