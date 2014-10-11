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


int main () {
  int t;
  inp(t);

  while (t--) {
    int n, m;
    inp(n); inp(m);
    int arr[n];
    int dp[n];

    for (int i = 0; i < n; i++) {
      inp(arr[i]);
    }

    sort(arr,arr+n);

    dp[n-1] = 1;
    
    for (int i = n-2; i >= 0; i--) {
      if (arr[i] != arr[i+1]) dp[i] = dp[i+1] + 1;
      else dp[i] = dp[i+1];
    }

    // for (int i = 0; i < n; i++) {
    //   printf("%d ",dp[i]);
    // }
    // printf("\n");


    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (i > 0 && arr[i] == arr[i-1]) continue;
      for (int j = i+1, k = n-1; j < k;) {
        if (arr[i] + arr[j] + arr[k] > m) {
          k--;
          continue;
        }

        if (arr[i] + arr[j] + arr[k] <= m) {
          if (k < n-1) sum +=  dp[j+1] - dp[k+1];
          else sum += dp[j+1];
        }
        j++;
        while (j < k && arr[j] == arr[j-1]) j++;
        // do {
        //   j++;
        // }while((j<k)&&(arr[j]==arr[k-1]));
      }
    }
    printf("%d\n",sum);
  }
}