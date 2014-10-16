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
typedef long long ll;
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
#define N 1000005

int next[N];

int main () {
  int n;
  inp(n);

  string a, b;
  cin >> a >> b;

  a = '$' + a + '#';
  b = '$' + b + b + '@';

  for (int i = 2; i <= n; i++) {
    int j = next[i-1];
    while (j > 0 && a[j] != a[i-1]) j = next[j];
    next[i] = j + 1;
  }
  n *= 2;
  
  int pos = 1;
  int ans = 0;
  int plen = 0;

  for (int i = 1; i <= n; i++) {
    while (pos > 0 && b[i] != a[pos]) {
      pos = next[pos];
    }

    if (plen < pos) {
      plen = pos;
      ans = i - plen;
    }
    pos++;
  }
  pi(ans); pn;
}