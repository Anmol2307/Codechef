#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>

using namespace std;
int stringtoint(string A)
{
  stringstream a;
  a<<A;
  int p;
  a>>p;
  return p;
}

int main () {
	string str = "0123";
	// rotate (str.begin(), str.begin()+2, str.end());
	printf("%d\n",stringtoint(str));
}