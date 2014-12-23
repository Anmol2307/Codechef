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
#define i64 long long
#define lli long long int
#define N 200002

lli modpow(lli base, lli exp) {
  lli result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return result;
}


int arr[N];

int main () {

  int t;
  inp(t);

  while (t--) {
    lli n;
    scanf("%lli",&n);
    int ma = 0;
    for (int i = 0; i < n; i++) {
      inp(arr[i]);
      if (arr[i] > ma) ma = arr[i];
    }

    lli ans = n;
    for (int d = -ma; d <= ma; d++) {

      lli sum[101];

      for (int i = 0; i <= 100; i++) {
        sum[i] = 0;
      }

      for (int j = 0; j < n; j++) {
        if (arr[j] - d > 0 && arr[j] - d <= ma) {
          ans = sum[arr[j] - d] + ans;
          if (ans > MOD) ans%=MOD;
          sum[arr[j]] = (sum[arr[j]] + sum[arr[j]-d] + 1);
          if (sum[arr[j]] > MOD) sum[arr[j]]%=MOD;
        }
      }
    }
    ans = modpow(2,n) - 1 - ans;
    if (ans < 0) ans += MOD;
    printf("%lli\n",ans);
  }
}