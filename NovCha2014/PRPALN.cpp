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
#define N 222222

bool checkpalin (string str) {
  int s = str.size();
  for (int i = 0; i < s/2; i++) {
    if (str[i] != str[s-i-1]) return false;
  }
  return true;
}

int main () {
  int t;
  inp(t);

  while (t--) {
    string str;
    cin >> str;
    int s = str.size();
    bool ans = true;
    for (int i = 0; i < s/2; i++) {
      if (str[i] != str[s-i-1]) {
        if (!checkpalin(str.substr(i,s-i-i-1)) & !checkpalin(str.substr(i+1,s-i-i-1))) {
          ans = false;
          break;
        }
        else break;
      }
    }
    
    if (ans) printf("YES\n");
    else printf("NO\n");
  }
}