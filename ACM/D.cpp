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
    int m, n;
    inp(m); inp(n);

    int mat[m][n];

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        inp(mat[i][j]);
      }
    }

    lli ans = INT_MIN;
    int len = min(m,n);
    
    int dp1[m][n][len];
    int dp2[m][n][len];

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = j+1; k < n; k++) {
          if (i+k-j < m) {
            ans = max(ans,dp[i][j][k]);
          }
        }
      }
    }
  }
}