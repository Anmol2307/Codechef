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

typedef long long int lli;

int main () {
  int t;
  inp(t);

  while (t--) {
    int n, q;
    inp(n);inp(q);

    for (int i = 0; i < q; i++) {
      int x, y;
      inp(x); inp(y);
    }

    
  }
}