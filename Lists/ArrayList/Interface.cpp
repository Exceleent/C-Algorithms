#include "ArrayList.hpp"
#include <fstream>
#include <stdio.h>
#include <iostream>

using namespace std;
void SwitchAction(char, int, ArrayList &);

int main()
{
	ArrayList list;
	char action;
	int number;
		do
		{
			action = getchar();
			SwitchAction(action, number, list);
		} while (action != EOF);
	return 0;
}

void SwitchAction(char action, int number, ArrayList &list)
{
	switch (action)
	{
	case 'F':
		cin >> number;
		printf("Dodajemy elemennt na poczatek listy %d \n", number);
		list.ArrayList::push_front(number);
		break;

	case 'B':
		cin >> number;
		printf("Dodajemy elemennt na koniec listy %d \n", number);
		list.ArrayList::push_back(number);
		break;

	case 'b':
		int size;
		size = list.ArrayList::size();
		if (size == 0)
			std::cout << "EMPTY \n";
		else
		{
			int element;
			//std::cout <<"usuwamy element ";
			element = list.ArrayList::pop_back();
		}
		break;

	case 'f':
		int size2;
		size2 = list.ArrayList::size();
		if (size2 == 0)
			std::cout << "EMPTY \n";
		else
		{
			int element;
			//std::cout <<"usuwamy element ";
			element = list.ArrayList::pop_front();
		}
		break;
	case 'S':
		int size3;
		printf("Rozmiar Listy  ");
		size3 = list.ArrayList::size();
		std::cout << size3 << "\n";
		break;

	case 'C':
		int element;
		cin >> number;
		element = list.ArrayList::find(number);
		break;

	default:
		break;
	}
}
