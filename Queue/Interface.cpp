#include "queue_imp.hpp"
#include <fstream>
#include <stdio.h>

using namespace std;
void SwitchAction(char, int, Queue &);
int main()
{
	Queue myqueue;
	char action;
	int number;
	if (read == NULL)
		perror("Error opening file");
	else
	{
		do
		{
			action = getchar();
			SwitchAction(action, number, myqueue);
		} while (action != EOF);
	}
	return 0;
}

void SwitchAction(char action, int number, Queue &myqueue)
{
	switch (action)
	{
	case 'A':
		cin >> number;
		printf("Dodajemy elemennt do kolejki %d \n", number);
		myqueue.Queue::push(number);
		//cout << MyStack.top() <<"\n";
		break;
	case 'D':
		if (myqueue.Queue::empty())
			cout << "EMPTY \n";
		else
		{
			cout << "Sciagamy element ";
			myqueue.Queue::pop();
		}
		break;

	case 'F':
		cin >> number;
		printf(" F %d\n", number);
		break;
	case 'S':
		printf("Size ");
		myqueue.Queue::size();
		break;
	default:
		break;
	}
}
