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
  int n;
  inp(n);

  while (n--) {
    int t;
    inp(t);

    lli ans = 0;
    for (int i = 0; i < t; i++) {
      lli d, o;
      scanf("%lli %lli", &d, &o);
      lli n = o/d;
      lli a = o%d;
      ans += (n*(a+o))/2;
    }
    if (ans & 1) printf("YES\n");
    else printf("NO\n");
  }
}