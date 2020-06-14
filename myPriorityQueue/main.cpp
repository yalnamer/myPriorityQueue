
#include "PriorityQueue.h"

int main()
{
	PriorityQueue q;

	q.add(Person("Jefferson", 5));
	q.add(Person("Ben", 7));
	q.add(Person("Pep", 8));
	q.add(Person("Lenny", 10));
	q.add(Person("Stan", 12));
	q.add(Person("Kelly", 13));
	q.add(Person("Joe", 14));

	q.remove(Person("Ben", 7));
	q.print();


}