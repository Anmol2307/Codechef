// map::count
#include <iostream>
#include <map>
#include <cstdio>

int main ()
{
  std::map<char,int> mymap;
  char c;

  mymap ['a']=101;
  mymap ['c']=202;
  mymap ['f']=303;

  for (c='a'; c<'h'; c++)
  {
    std::cout << c;
    if (mymap.count(c)>0)
      std::cout << " is an element of mymap.\n";
    else {
      // printf("%lu\n",mymap.count(c));
      // printf("%lu\n",mymap.count(c));
      
      std::cout << " is not an element of mymap.\n";
    }
  }

  return 0;
}