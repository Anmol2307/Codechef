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
typedef long long lli;
typedef vector <int> vi;
typedef pair< int ,int > pii;
typedef istringstream iss;
typedef ostringstream oss;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)
 
#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) printf("%lld",n)
#define ps printf(" ")
#define pn printf("\n")
#define N 222222
#define mod 10000007


int main () {
  int n, m;
  inp(n); inp(m);
  lli arr[n][m];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%lli",&arr[i][j]);
    }
  }

  lli dp[n][m];
  memset(dp,0,sizeof dp);

  for (int i = 0; i < n; i++) {
    dp[i][0] = arr[i][0];
  }

  for (int i = 1; i < m; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        dp[j][i] = (dp[j][i] + (dp[k][i-1]*arr[j][i])%mod)%mod;
        if (dp[j][i] < 0) dp[j][i] += mod;
      }
    }
  }

  lli ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans + dp[i][m-1])%mod;
    if (ans < 0) ans += mod;
  }
  ans %= mod;
  printf("%lli\n",ans);
}