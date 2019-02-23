#include "ArrayList.hpp"
#include <iostream>
#include <cstddef>
ArrayList::ArrayList()
{
   array = new int[100];
   lengtharray = 100;
   listsize = 0;
}

void ArrayList::resize()
{
   int *newarray = new int[lengtharray * 2];
   for (int i = 0; i < lengtharray; i++)
   {
      newarray[i] = array[i];
   }
   array = newarray; 
   lengtharray *= 2;
}
bool ArrayList::needtoresize()
{
   return lengtharray == listsize;
}

void ArrayList::push_front(int x)
{
   if (needtoresize())
      resize();
   for (int i = listsize; i > 0; i--)
   {
      array[i] = array[i - 1];
   }
   array[0] = x;
   listsize++;
}
int ArrayList::pop_front()
{
   if (listsize == 0)
      return 0;
   else
   {
      int value;
      value = array[0];
      for (int i = 0; i < listsize; i++)
      {
         array[i] = array[i + 1];
      }
      std::cout << value << "\n";
      listsize--;
      return value;
   }
}
void ArrayList::push_back(int x)
{
   if (needtoresize())
      resize();
   array[listsize] = x;
   listsize++;
}
int ArrayList::pop_back()
{
   if (listsize == 0)
      return 0;
   else
   {
      int value;
      listsize--;
      value = array[listsize];
      std::cout << "Usuwany element " << value << "\n";
      return value;
   }
}
int ArrayList::find(int x)
{
   for (int i = 0; i < listsize; i++)
   {
      if (array[i] == x)
      {
         int value;
         value = array[i];
         std::cout << "Istnieje " << value << "\n";
         return value;
      }
   }
   std::cout << "Brak elementu" << x << "\n";
   return 0;
}
void ArrayList::erase(int position)
{
   for (int i = position; i < listsize; i++)
      array[i] = array[i + 1];
   listsize--;
}
int ArrayList::size()
{
   return listsize;
}
