#include "ArrayListSorted.hpp"
#include <iostream>
#include <limits.h>
#include <cstddef>
const int definedsize = 1000000;
SortedArrayList::SortedArrayList()
{
  array = new int[definedsize];
  for (int i = 0; i < definedsize; i++)
  {
    array[i] = INT_MAX;
  }
  nums = 0;
}

void SortedArrayList::push(int x)
{
  if (nums == definedsize)
    std::cout << "List is full\n";
  else if (nums == 0)
  {
    array[0] = x;
    nums++;
  }
  else
  {
    int *iterator = std::lower_bound(array, array + nums, x); // Zwraca nie przeskalowany indeks, pod ktorym bedziemy chcieli umiesci element
    int index = iterator - array;
    for (int i = nums; i >= index; i--)
    {
      array[i] = array[i - 1]; // Przesuwamy elementy
    }
    array[index] = x;
    nums++;
  }
}
int SortedArrayList::pop()
{
  if (nums == 0)
    std::cout << "List is empty\n";
  else
  {
    int value;
    value = array[0];
    for (int i = 0; i <= nums - 1; i++)
    {
      if (i == nums - 1)
        break;
      array[i] = array[i + 1];
    }
    nums--;
    return value;
  }
}
int SortedArrayList::find(int x)
{
  for (int i = 0; i < nums; i++)
  {
    if (array[i] == x)
      return array[i];
  }
  return -1;
}

int SortedArrayList::erase(int position)
{
  int value;
  value = array[position];
  for (int i = position; i < nums; i++)
  {
    array[i] = array[i + 1];
    nums--;
  }
  return value;
}

int SortedArrayList::size() const
{
  return nums;
}

void SortedArrayList::remove(int x)
{
  int temp = nums;
  int i = 0;
  for (i; i < nums; i++)
  {
    if (array[i] == x)
    {
      for (temp; temp - 2 >= i; temp--)
      {
        array[temp - 2] = array[temp - 1];
      }
      nums--;
    }
  }
}

void SortedArrayList::print()
{
  for (int i = 0; i < nums; i++)
  {
    std::cout << array[i] << "\n";
  }
}

void SortedArrayList::unique()
{
  for (int i = 0; i < nums; i++)
  {
    if (array[i] == array[i + 1])
    {
      erase(i);
    }
  }
}

int SortedArrayList::getelement(int index) const
{
  return array[index];
}

SortedArrayList SortedArrayList::merge(const SortedArrayList &a, const SortedArrayList &b)
{
  int a_index = 0;
  int b_index = 0;
  int avalue;
  int bvalue;
  int a_size = a.size();
  int b_size = b.size();
  int size = a_size + b_size;
  SortedArrayList *Sum = new SortedArrayList();
  for (int i = 0; i < size; i++)
  {
    avalue = a.getelement(a_index);
    bvalue = b.getelement(b_index);
    // std::cout << avalue <<"\n" <<bvalue ;
    if (avalue < bvalue && (a_index !=(a_size)))
    {
      Sum->array[i] = avalue;
      a_index++;
      Sum->nums++;
      //std::cout << Sum.array[i] <<"\n";
    }
    else
    {
      Sum->array[i] = bvalue;
      b_index++;
      Sum->nums++;
      //std::cout << Sum.array[i] << "\n";
    }
    avalue = 0;
    bvalue = 0;
  }
  return *Sum;
}
