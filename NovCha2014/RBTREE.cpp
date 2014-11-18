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


int main () {
  int q;
  inp(q);

  int black = 1;
  while (q--) {
    string str;
    int x, y;
    cin >> str;
    stack<int> stk1;
    stack<int> stk2;

    if (str == "Qb" || str == "Qr") {
      inp(x); inp(y);
      int tmpx = x;
      int tmpy = y;
      while (tmpx != 1) {
        if ((tmpx&1) == 0) {
          stk1.push(tmpx);
          tmpx/=2;
        }
        else {
          stk1.push(tmpx);
          tmpx-=1;
          tmpx/=2;
        }
      }
      stk1.push(1);
      
      while (tmpy != 1) {
        if ((tmpy&1) == 0) {
          stk2.push(tmpy);
          tmpy /= 2;
        }
        else {
          stk2.push(tmpy);
          tmpy-=1;
          tmpy/=2;
        }
      }
      stk2.push(1);
      bool flag = false;
      int len = 0;
      while (!stk1.empty() && !stk2.empty()) {
        if (stk1.top() == stk2.top()) {
          stk1.pop();
          stk2.pop();
        }
        else {
          len = stk1.size() + stk2.size() + 1;
          flag = true;
          break;
        }
      }
      if (!flag) len = stk1.size() + stk2.size() + 1;
      if ((len&1) == 0) {
        printf("%d\n",len/2);
      }
      else {
        int depth = log2(x);
        if ((depth&1) == 0) {
          if ((black == 1 && str == "Qb") || (black == 0 && str == "Qr")) {
            printf("%d\n",len/2+1);
          }
          else {
            printf("%d\n",len/2); 
          }
        }
        else {
          if ((black == 0 && str == "Qb") || (black == 1 && str == "Qr")) {
            printf("%d\n",len/2+1);
          }
          else {
            printf("%d\n",len/2); 
          }
        }
      }
    }
    else {
      black = 1 - black;
    }
  }
}