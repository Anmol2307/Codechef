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
#define maxn 200005

lli dp[maxn];
lli arr[maxn];

int main () {
  int n;
  inp(n);
  
  for (int i = 1; i <= n; i++) {
    scanf("%lli", &arr[i]);
  }
  
  for (int i = n-1; i >= 1; i--) {
    dp[i] = INT_MAX;
    for (int x = 0;; x++) {
      int val = pow(2,x);
      int j = i + val;
      if (j <= n) dp[i] = min(dp[i], dp[j] + abs(arr[i] - arr[j]));
      else break;
    }
  }

  printf("%lli\n",dp[1]);
}