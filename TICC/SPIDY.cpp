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
#define maxn 1000005

int dp[maxn];

void pre () {

  for (int i = 1; i < maxn; i+= 2) {
    dp[i] = -1;
  }
  
  dp[2] = -1;
  dp[4] = -1;
  dp[6] = 0;

  for (int i = 8; i < maxn; i+= 2) {
    if (((i/2)%4)%3 == 0) dp[i] = 1;
    else if ((i/2)%3 == 0) dp[i] = 0;
    else dp[i] = -1;
  }
}

int main () {
  int t;
  inp(t);

  pre();

  // for (int i = 1; i <= 50; i++) {
  //   printf("%d %d\n",i,dp[i]);
  // }

  while (t--) {
    int n;
    inp(n);
    if (dp[n] == 1) printf("YES\n");
    else if (dp[n] == 0) printf("NO\n");
    else if (dp[n] == -1) printf("RIDICULOUS\n");
  }
}