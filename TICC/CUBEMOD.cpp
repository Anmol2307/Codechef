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

int main () {
  int t;
  inp(t);

  while (t--) {
    lli a, b, p;
    scanf("%lli %lli %lli", &a, &b, &p);
    
    lli count = 0;
    lli i;
    for (i = 1; i < p; i++) {
      if ((i*i*i) % p == 1) {
        count++;  
      }
    }

    lli start = a/p;
    lli end = b/p - 1;
    lli sum = count*(end-start + 1);
    
    lli ev = (end+1)*p;
    lli sv = start*p;
    for (i = 1; ev + i <= b;i++) {
      if ((i*i*i) % p == 1) {
        sum++;
      }
    }

    for (i = 1; sv + i < a; i++) {
      if ((i*i*i) % p == 1) {
        sum--;
      }
    }
    
    printf("%lli\n",sum);
  }
}