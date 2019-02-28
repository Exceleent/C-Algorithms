#include "SortedLinkedList.hpp"
#include <iostream>
const int size_list = 1000000;
struct Node;
SortedLinkedList::SortedLinkedList()
{
	this->head = NULL;
	this->tail = NULL;
	this->nums = 0;
}

void SortedLinkedList::push(int element)
{
	if (this->nums == size_list)
		std::cout << "List is empty\n";
	else if (this->nums == 0)
	{
		Node *new_node = new Node;
		new_node->next = NULL;
		new_node->prev = NULL;
		new_node->x = element;
		this->tail = new_node;
		this->head = new_node;
		this->nums = this->nums + 1;
	}
	else if (element <= this->head->x)
	{
		Node *new_node = new Node;
		new_node->x = element;
		new_node->next = this->head;
		new_node->prev = NULL;
		this->head->prev = new_node;
		this->head = new_node;
		this->nums++;
	}
	else if (element >= this->tail->x)
	{
		Node *new_node = new Node;
		new_node->x = element;
		new_node->next = NULL;
		new_node->prev = this->tail;
		this->tail->next = new_node;
		this->tail = new_node;
		this->nums++;
	}
	else
	{
		Node *new_node = new Node;
		new_node->x = element;
		new_node->next = NULL;
		new_node->prev = NULL;
		Node *temp = this->head;
		while (1)
		{
			if (temp->next->x >= element)
			{
				temp->next->prev = new_node;
				new_node->next = temp->next;
				temp->next = new_node;
				new_node->prev = temp;
				this->nums++;
				break;
			}
			temp = temp->next;
		}
	}
}
int SortedLinkedList::pop()
{
	int value;
	value = this->head->x;
	this->head = this->head->next;
	this->nums = this->nums - 1;
	return value;
}

int SortedLinkedList::erase(int position)
{
	Node *erase_node = new Node;
	erase_node = this->head;
	if (position >= nums)
	{
		return -1;
	}
	int return_value;
	if (position == this->nums - 1)
	{
		return_value = this->tail->x;
		this->tail->prev->next == NULL;
		this->tail = this->tail->prev;
		this->nums--;
		return return_value;
	}
	if (position == 0)
	{
		if (this->nums == 1)
		{
			return_value = this->head->x;
			this->head = NULL;
			return return_value;
			this->nums = this->nums - 1;
		}
		else
		{
			return_value = this->head->x;
			this->head = this->head->next;
			this->head->prev = NULL;
			this->nums = this->nums - 1;
			return return_value;
		}
	}
	else
	{

		for (int i = 0; i < position; i++)
		{
			if (erase_node->next == NULL)
			{
				return -1;
			}
			erase_node = erase_node->next;
		}
		return_value = erase_node->x;
		erase_node->prev->next = erase_node->next;
		erase_node->next->prev = erase_node->prev;
		this->nums = this->nums - 1;
	}
	return return_value;
}

int SortedLinkedList::find(int x)
{
	Node *find = new Node;
	find = this->head;
	for (int i = 0; i < nums; i++)
	{
		if (find->x == x)
			return i;
		find = find->next;
	}
	return -1;
}
void SortedLinkedList::remove(int x)
{
	Node *deleted = new Node;
	deleted = this->head;
	while (deleted == this->head && deleted->x == x)
	{
		this->head = this->head->next;
		deleted = this->head;
		this->nums = this->nums - 1;
		if (deleted->x != x)
			return;
	}

	deleted = this->tail;
	while (deleted == this->tail && deleted->x == x)
	{
		this->tail = this->tail->prev;
		deleted = this->tail;
		this->nums = this->nums - 1;
		if (deleted->x != x)
			return;
	}

	deleted = this->head;
	while (1)
	{
		if (deleted->next == NULL)
			break;
		deleted = deleted->next;
		if (deleted->x == x)
		{
			deleted->prev->next = deleted->next;
			deleted->next->prev = deleted->prev;
			this->nums = this->nums - 1;
		}
	}
}

int SortedLinkedList::size() const
{
	return this->nums;
}

int SortedLinkedList::get(int x) const
{
	Node *temp = new Node;
	temp = this->head;
	for (int i = 0; i < x; i++)
	{
		temp = temp->next;
	}
	return temp->x;
}

SortedLinkedList SortedLinkedList::merge(const SortedLinkedList &a, const SortedLinkedList &b)
{
	if (a.size() + b.size() == size_list)
	{
		std::cout << "Cannot merge list they are too big";
	}
	else
	{
		SortedLinkedList Sum;
		Sum = a;
		for (int i = 0; i < b.size(); i++)
		{
			Sum.push(b.get(i));
		}

		return Sum;
	}
}

void SortedLinkedList::print()
{
	Node *temp = new Node;
	temp = this->head;
	for (int i = 0; i < this->nums; i++)
	{
		std::cout << temp->x << "\n";
		temp = temp->next;
	}
}
void SortedLinkedList::unique()
{
	Node *temp = new Node;
	temp = this->head;
	for (int i = 0; i < this->nums; i++)
	{
		if (temp->x == temp->next->x)
		{
			remove(temp->x); // usuwamy wszystkie powtorzenia
			push(temp->x); // dodajemy element
		}
		temp = temp->next;
	}
}
