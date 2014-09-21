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


int gcd(int a, int b) {
  while(b) b ^= a ^= b ^= a %= b;
  return a;
}


int main () {
  int t;
  inp(t);

  while (t--) {
    int n;
    inp(n);
    int arr[n];
    for (int i = 0; i < n; i++) {
      inp(arr[i]);  
    }
    int g = arr[0];

    for (int i = 1; i < n; i++) {
      g = gcd(arr[i],g);
    }
    if (g == 1) printf("%d\n",n);
    else printf("-1\n");
  }
}