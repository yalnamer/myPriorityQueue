#pragma once
#include "Person.h"

class PriorityQueue
{
	int max = 1000;
	Person queue[1000];

	int end;
	int size;

	void bubbleDown(int index);
	void bubbleUp(int index); 

	

public:

	PriorityQueue();

	Person poll();

	Person peek();

	void add(Person person);

	void remove(Person person);

	int getSize();

	bool isFull();

	void print();
};

