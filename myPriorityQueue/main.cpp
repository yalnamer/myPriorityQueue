
#include "PriorityQueue.h"

int main()
{
	PriorityQueue q;

	bool over = false;

	while (!over)
	{
		std::cout << "\n\n[ Priority Queue Menu ]" << std::endl;
		std::cout << "  -> 1. Add person to queue." << std::endl;
		std::cout << "  -> 2. Look at front of queue." << std::endl;
		std::cout << "  -> 3. Grab person at the front of queue." << std::endl;
		std::cout << "  -> 4. Remove a certain person from queue." << std::endl;
		std::cout << "  -> 0. Quit" << std::endl;
		std::cout << "  -> ***Note- Lower Priority Number Indicates Higher Priorirty, 1 has more priority than 6" << std::endl;


		int choice;
		std::cout << "Enter Option Number: ";
		std::cin >> choice;

		if (choice == 0)
			over = true;

		if (choice == 1)
		{
			std::string name;
			int p;

			std::cout << "Enter Person Name: ";
			std::cin >> name;
			std::cout << "Enter Person Priority (Must be > -1): ";
			std::cin >> p;
			
			if (p < 0)
			{
				std::cout << "\n  [!] Invalid priority, must be 0 or greater\n\n";
			}
			else
			{
				q.add(Person(name, p));
			}
		}

		if (choice == 2)
		{
			Person p = q.peek();

			if (p.priority == -1)
				std::cout << "\n  [!]ERROR: The Queue is Empty\n" << std::endl;
			else
				std::cout << "[+] " << p.name << " is in front of queue" << std::endl;
		}

		if (choice == 3)
		{
			Person p = q.poll();
			if (p.priority == -1)
				std::cout << "\n  [!]ERROR: The Queue is Empty\n" << std::endl;
			else
				std::cout << "[+] " << p.name << "has been removed from the queue" << std::endl;
		}

		if (choice == 4)
		{
			std::string name;
			std::cout << "Name of person you would like to remove: ";
			std::cin >> name;
			
			q.remove(Person("Name", -2));
		}

		std::cout << "\n[ Info ] \n";
		std::cout << "  [+] Size of Queue: " << q.getSize() << std::endl;
		q.print();

	}

}