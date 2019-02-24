#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList()
{
	this->head = NULL;
	this->tail = NULL;
	this->list_size = 0;
}

void LinkedList::push_front(int element)
{
	if (list_size == 100)
	{
		std::cout << "List is full \n";
		return;
	}
	else
	{
		Node *new_node = new Node;
		new_node->prev = NULL;
		new_node->next = NULL;

		if (this->head == NULL)
		{
			new_node->x = element;
			this->head = new_node;
			this->tail = new_node;
			this->list_size = this->list_size + 1;
		}
		else
		{
			this->head->prev = new_node;
			new_node->next = this->head;
			new_node->x = element;
			this->head = new_node;
			this->list_size = this->list_size + 1;
		}
		return;
	}
}

void LinkedList::push_back(int element)
{
	if (list_size == 100)
	{
		std::cout << "List is full\n";
		return;
	}
	else
	{
		Node *new_node = new Node;
		new_node->prev = NULL;
		new_node->next = NULL;

		if (this->head == NULL)
		{
			this->head = new_node;
			this->tail = this->head;
			new_node->x = element;
			this->list_size = this->list_size + 1;
		}
		else
		{
			this->tail->next = new_node;
			new_node->prev = this->tail;
			this->tail = new_node;
			new_node->x = element;
			this->list_size = this->list_size + 1;
		}
	}
}

int LinkedList::pop_front()
{
	if (list_size == 0)
	{
		std::cout << "List is empty\n";
		return 0;
	}
	else if (list_size == 1)
	{
		int element = this->head->x;
		this->head = NULL;
		this->tail - NULL;
		this->list_size = this->list_size - 1;
		return element;
	}
	else
	{
		int element;
		Node *temp = this->head;
		element = this->head->x;
		this->head = this->head->next;
		this->head->prev = NULL;
		this->list_size = this->list_size - 1;
		return element;
	}
}

int LinkedList::pop_back()
{
	if (list_size == 0)
	{
		std::cout << "List is empty\n";
		return -1;
	}
	else if (list_size == 1)
	{
		int element;
		element = this->head->x;
		this->tail = NULL;
		this->head = NULL;
		this->list_size = this->list_size - 1;
		return element;
	}
	else
	{
		int element;
		Node *temp = this->tail;
		element = this->tail->x;
		this->tail = this->tail->prev;
		this->tail->next = NULL;
		this->list_size = this->list_size - 1;
		return element;
	}
}

int LinkedList::erase(int pos)
{
	if (pos == 0)
	{
		int temp = pop_front();
		this->list_size = this->list_size - 1;
		return temp;
	}
	else if (pos == this->list_size - 1)
	{
		int temp2 = pop_back();
		this->list_size = this->list_size - 1;
		return temp2;
	}
	else
	{
		int value;
		Node *temp = this->head;
		int number = 0;
		while (temp)
		{
			if (number == pos)
			{
				value = temp->x;
				Node *temp2 = temp->prev;
				Node *temp3 = temp->next;
				temp->prev = NULL;
				temp->next = NULL;
				temp2->next = temp3;
				temp3->prev = temp2;
				this->list_size = this->list_size - 1;
				return value;
			}
			number++;
			temp = temp->next;
		}
	}
}

int LinkedList::insert(int pos, int x)
{
	if (pos == 0)
		push_front(x);
	else if (pos == list_size - 1)
		push_back(x);
	else
	{
		int number = 0;
		Node *temp = this->head;
		while (temp)
		{
			if (number == pos)
			{
				Node *temp2;
				Node *temp3;
				temp2 = this->head;
				temp3 = this->head->next;
				temp->prev = temp2;
				temp->next = temp3;
				temp->x = x;
				this->head = temp;
				return number;
			}
			number++;
			temp = temp->next;
		}
	}
}

int LinkedList::listsize()
{
	int size = this->list_size;
	return size;
}

int LinkedList::find(int x)
{
	if (this->list_size == 0)
		return -1;
	else
	{
		Node *temp = this->head;
		int number = 0;
		while (temp)
		{
			if (temp->x == x)
				return number;
			number++;
			temp = temp->next;
		}
		return -1;
	}
}

void LinkedList::print()
{
	Node *printing = this->head;
	for (int i = 0; i < this->list_size; i++)
	{
		std::cout << printing->x << "\n";
		printing = printing->next;
	}
}
