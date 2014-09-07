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

#define MOD 1000000007
long long int binomialCoeff(int n, int k)
{
    long long int C[k+1];
    memset(C,0, sizeof(C));
    
    C[0] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = min(i, k); j > 0; j--)
            C[j] = (C[j] + C[j-1])%MOD;
    }
    return C[k];
}

int main () {
  int n;
  inp(n);

  if (n < 13) printf("%d\n",0);
  else {
    if ((n & 1) == 0) n--;
    long long int val = binomialCoeff((n-1)/2,6);
    printf("%lli\n",val);
  }
}