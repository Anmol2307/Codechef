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
typedef pair<int,int> pii;
typedef long long int lli;

lli gcd (lli a, lli b) {
  while (b) {
    return gcd(b,a%b);
  }
  return a;
}

int main () {
  int t;
  inp(t);

  while (t--) {
    lli n;
    scanf("%lli", &n);

    lli val = n*(n-1);
    lli g = gcd(val,8);

    printf("%lli/%lli\n",val/g,8/g);
  }
}