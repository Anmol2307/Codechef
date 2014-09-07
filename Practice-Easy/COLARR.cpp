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
long long int dp[1001];
int B[1001][1001];
int col[1001], n, m, k;

long long int find (int index, int k) {
  if (dp[index] != -1) return dp[index];
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    if (col[index] == i) {
      ans = max(ans,B[index][i] + find(index+1,k));
    }
    else {
      ans = max (ans,B[index][i] - )
    }
  } 
} 


int main () {
  int t;
  inp(t);

  while (t--) {
    inp(n); inp(m); inp(k);
    for (int i = 1; i <= n; i++) {
      inp(col[i]);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        inp(B[i][j]);
      }
    }

    long long int ans = find(1,k);
    // long long int ans = 0;
    // for (int i = 1; i <= n; i++) {
    //   long long int max = -1;
    //   for (int j = 1; j <= m; j++) {
    //     int x; inp(x);
    //     if (col[i] == j) {
    //       if (B[i][j] > max) max = B[i][j];
    //     }
    //     else {
    //       if ((B[i][j] - x) > max) max = B[i][j] - x;
    //     }
    //   }
    //   // printf("%d %lli\n",i,max);
    //   ans += max;
    // }
    // printf("%lli\n",ans);
  }
 }