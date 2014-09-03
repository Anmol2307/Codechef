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

  while(t--) {
    long long int n;
    scanf("%lli",&n);
    if (n < 2) printf("%d\n",0);
    else {
      long long ans = 2*n*(n-1)*(n-1) + n*(n-1)*(n-2) + 2*n*(n-1)*(n-2)*(n-2);
      printf("%lli  \n",ans);
    }
  }
}
