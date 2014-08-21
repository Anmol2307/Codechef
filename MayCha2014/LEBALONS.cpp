#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <cctype>
#include <list>
#include <stack>
#include <fstream>
#include <utility>
#include <iomanip>
#include <climits>

using namespace std;
#define pb push_back
#define all(s) s.begin(),s.end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define F(i,a,b) for(int i=a;i>=b;i--)
#define PI 3.1415926535897932384626433832795
#define BIG_INF 7000000000000000000LL
#define mp make_pair
#define eps 1e-9
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define mod 1000000007
#define mm 10000000
#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define EPS 1e-9
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)


typedef long long int LL;

string inttostring(int n)
{
  stringstream a;
  a<<n;
  string A;
  a>>A;
  return A;
}

int stringtoint(string A)
{
  stringstream a;
  a<<A;
  int p;
  a>>p;
  return p;
}

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}

///////////////////////////////////////////////////////////////////////////////////////////

// prob = (total cost of subsets with atleast m colors)/(total number of substes with atleat m colous)

long long int mypow(int a, int b) {
  long long int ans = 1;
  for (int i = 0; i < b; i++) {
    ans *= a;
  }
  return ans;
}

int main () {
  
  int t;
  inp(t);

  while (t--) {
    int n, m;
    inp(n);inp(m);

    vector <int> colors(n+1,0);
    vector <int> cost(n+1,0);
    int c=0;
    for (int i = 0; i < n; i++) {
      int x, y;
      inp(x); inp(y);
      if (colors[x] == 0) c++; 
      colors[x]++;
      cost[x] += y;
    }
    // Total number of subsets with atleast m colors 
    long long int dp[c+1][c+1];
    memset(dp,0,sizeof(dp));
    for (int i = 0; i <= c; i++) {
      dp[i][0] = 1;
    }

    

    for (int i = 1; i <= c; i++) {
      for (int j = 1; j <= c; j++) {
        dp[i][j] = dp[i-1][j] + (long long int)(dp[i-1][j-1]*(mypow(2,colors[i]) - 1));
        
      }
    }
    // for (int i = 1; i <= c; i++) {
    //   for (int j = 1; j <= c; j++) {
    //     printf("%d ",dp[i][j]);
    //   }
    //   printf("\n");
    // }
    // exit(0);

    // Total cost of all the subsets with atlest m colors
    long long int dp2[c+1][c+1];
    for (int i = 0; i <= c; i++) {
      for (int j = 0; j <= c; j++) {
        if (i==0 || j==0) dp2[i][j] = 0;
        else {
          dp2[i][j] = dp2[i-1][j] + (long long int)(dp2[i-1][j-1]*(mypow(2,colors[i]) - 1)  + dp[i-1][j-1]*cost[i]*(mypow(2,colors[i]-1)));
        }
      }
    }

    // for (int i = 1; i <= c; i++) {
    //   for (int j = 1; j <= c; j++) {
    //     printf("%d ",dp2[i][j]);
    //   }
    //   printf("\n");
    // }
    // exit(0);

    int num = 0, den=0;
    for (int i = m; i <= c; i++) {
      num += dp2[c][i];
      den += dp[c][i];
    }
    // printf("%d %d\n",num,den);
    if (den != 0) {
      double ans = (double)num/den;
      printf("%lf\n",ans);
    }
    else if (num ==0 || den == 0){
      printf("%lf\n",(double)0);
    }
  }
}