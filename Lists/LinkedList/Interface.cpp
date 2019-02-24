#include "LinkedList.hpp"
#include <fstream>
#include <stdio.h>
#include <iostream>

using namespace std;
void SwitchAction(char, int, LinkedList &);

int main()
{
	LinkedList list;
	char action;
	int number;
	do
	{
		action = getchar();
		SwitchAction(action, number, list);
	} while (action != EOF);
	return 0;
}

void SwitchAction(char action, int number, LinkedList &list)
{
	switch (action)
	{
	case 'F':
		cin >> number;
		std::cout << "Front Adding " << number << "\n";
		list.LinkedList::push_front(number);
		break;

	case 'B':
		cin >> number;
		std::cout << "Back Adding " << number << "\n";
		list.LinkedList::push_back(number);
		break;

	case 'b':
		int size;
		size = list.LinkedList::listsize();
		if (size == 0)
			std::cout << "List is empty  \n";
		else
		{
			int element;
			element = list.LinkedList::pop_back();
			std::cout << "Deleting element " << element << endl;
		}
		break;

	case 'f':
		int size2;
		size2 = list.LinkedList::listsize();
		if (size2 == 0)
			std::cout << "List is empty \n";
		else
		{
			int element;
			element = list.LinkedList::pop_front();
			std::cout << "Front deleting " << element << endl;
		}
		break;
	case 'S':
		int size3;
		printf("Size of List ");
		size3 = list.LinkedList::listsize();
		std::cout << size3 << "\n";
		break;

	case 'C':
		int element;
		cin >> number;
		element = list.LinkedList::find(number);
		std::cout << "We found elment " << element << endl;
		break;

	case 'P':
		list.print();
		break;

	default:
		break;
	}
}
