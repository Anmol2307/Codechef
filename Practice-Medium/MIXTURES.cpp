#include <bits/stdc++.h>

using namespace std;

int main () {

  int n;
  while (scanf("%d",&n) == 1) {
    int arr[n];
    for (int i=0; i < n; i++) {
      scanf("%d",&arr[i]);
    }
    int dp[n][n];
    int cdp[n][n];

    for (int i=0; i<n; i++) {
      dp[i][i]=arr[i];
      cdp[i][i]=0;
    }

    for (int l =2; l <= n; l++) {
      for (int i = 0; i < n-l+1; i++) {
        int j = i+l-1;
        cdp[i][j] = INT_MAX;
        for (int k =i; k <= j-1; k++) {
          int cost = dp[i][k]*dp[k+1][j];
          if ((cost + cdp[k+1][j] + cdp[i][k]) < cdp[i][j]) {
            dp[i][j] = (dp[i][k] + dp[k+1][j])%100;
            cdp[i][j] = cost + cdp[k+1][j] + cdp[i][k];
          }
        }
      }
    }
    printf("%d\n",cdp[0][n-1]);
  }

}
