#include <iostream>
#include<unordered_set>
#include "Vector.h"


int main() {
   MyVector:: Vector<int> obj(20);
   for (int i = 0; i < 20; ++i)
   {
       int a = rand() % 200;
       obj.Push_back(a);
   }
   std::cout << "The original vector:: \n";
   obj.Print();
   std::unordered_set<int>MySet;
   for (int i = 0; i < 20; ++i)
   {
       MySet.insert(obj[i]);
   }
   std::cout << std::endl << "The elements after removing them to set:: \n";
   for (auto it : MySet)
   {
       std::cout << it << ' ';
   }
   std::cout << std::endl;
    return 0;
}
