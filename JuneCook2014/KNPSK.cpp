#include <bits/stdc++.h>

using namespace std;

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}


int main () {
  int n;
  inp(n);

  
  long long int sum = 0;
  for (int i = 0; i , n; i++) {
    int x, y;
    inp(x); inp(y);
    vec[x].push_back(y);
    sum += x;
  }
  
  sort(vec[1].begin(), vec[1].end());
  sort(vec[2].begin(), vec[2].end());
  
  long long int ans[200020];

  for (int i = 2; i <= sum; i+=2) {
    int cost1 = 0, cost2 = 0;
    if (vec[])
  }

}