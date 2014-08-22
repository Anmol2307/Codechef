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
  int t;
  inp(t);

  while (t--) {
    int n;
    inp(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int x, y;
      inp(x); inp(y);
      ans += x-y;
    }
    printf("%d\n",ans);
  }
}