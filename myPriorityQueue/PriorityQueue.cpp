#include "PriorityQueue.h"

PriorityQueue::PriorityQueue()
{
	end = -1;
	size = 0;
}


Person PriorityQueue::poll()
{
	if (size == 0)
		return Person("EMPTY QUEUE", -1);
	

	if (size == 1)
	{
		end--;
		size--;
		return queue[(end + 1)];
	}
	else if (size > 1)
	{
		Person temp = queue[0];
		queue[0] = queue[end];
		end--;
		size--;

		bubbleDown(0);

		return temp;
	}
}

Person PriorityQueue::peek()
{
	if (size == 0)
		return Person("EMPTY QUEUE", -1);

	return queue[0];
}

void PriorityQueue::add(Person person)
{
	if (!isFull())
	{
		queue[++end] = person;
		size++;

		//Make sure min heap property is maintained
		bubbleUp(end);
	}
	else
	{
		std::cout << "\n[!] ERROR: Queue is Full ";
	}
}

void PriorityQueue::remove(Person person)
{
	for (int i = 0; i < size; i++)
	{
		if ((queue[i].name == person.name) && (queue[i].priority == person.priority))
		{
			Person temp = queue[end];
			queue[end] = queue[i];
			queue[i] = temp;
			bubbleDown(i);
			size--;
			end--;
			return;
		}
	}
}

int PriorityQueue::getSize()
{
	return size;
}

bool PriorityQueue::isFull()
{
	if (size == 1000)
		return true;
	else
		return false;
}

void PriorityQueue::print()
{
	std::cout << "[+] Printing names in queue\n";

	for(int i = 0; i < size; i++)
	{
		std::cout << "  [-] " << queue[i].name << std::endl;
	}

}

void PriorityQueue::bubbleDown(int index)
{
	//Children
	int leftIndex = (2 * index) + 1;
	int rightIndex = (2 * index) + 1;

	bool leftExist = false;
	bool rightExist = false;

	if (rightIndex <= end)
	{
		//If right tree exists, so does the left tree
		leftExist = true;
		rightExist = true;
	}
	else if (leftIndex <= end)
	{
		leftExist = true;
	}
	
	if (!leftExist)
		return;

	//Look at smallest child
	bool leftMin = true;
	Person current = queue[index];

	//Children priority
	if (rightExist)
	{
		int left = queue[leftIndex].priority;
		int right = queue[rightIndex].priority;

		if (right < left)
			leftMin = false;
	}

	Person min;
	int minIndex;

	if (leftMin)
	{
		min = queue[leftIndex];
		minIndex = leftIndex;
	}
	else
	{
		min = queue[rightIndex];
		minIndex = rightIndex;
	}

	//If child is greater/equal than current person, then we are in correct position.
	if (current.priority <= min.priority)
	{
		return;
	}
	else
	{
		//Swap
		queue[minIndex] = current;
		queue[index] = min;

		bubbleDown(minIndex);
	}


}

void PriorityQueue::bubbleUp(int index)
{
	//No need to Bubble up at the root
	if (index == 0)
		return;

	//We are dealing with a tree.
	int parentIndex;
	if (index % 2 == 0)
		parentIndex = (index - 2) / 2;
	else
		parentIndex = (index - 1) / 2;

	Person child = queue[index];
	Person parent = queue[parentIndex];

	//If the heap invariant property is mainted no need to continue to bubble up
	if (child.priority > parent.priority)
		return;

	//Swap places
	queue[parentIndex] = child;
	queue[index] = parent;

	bubbleUp(parentIndex);
}
