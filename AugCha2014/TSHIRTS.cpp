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
#include <iterator>

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
bool matrix[11][101];
int dp[1024][101];
int n;

int recurse (int num, int index) {

  if (index > 100) {
    return (num%(1<<11)==0);
  }
  if (dp[num][index] != -1) return dp[num][index];

  int val = recurse(num,index+1);
  bool tshirtPre[11];
  bool tshirtNum[11];

  for (int i = 1; i <= n; i++) {
    tshirtPre[i] = matrix[i][index];
    tshirtNum[i] = (num>>(i-1))%2;
  }

  for (int i = 1; i <= n; i++) {
    if (tshirtPre[i] && tshirtNum[i]) {
      val =  (val+recurse(num - (1<<(i-1)),index+1))%mod;
    }
  }
  // printf("%d %d %d\n",num,index,val);
  dp[num][index] = val;
  return val;
}

int main () {
  int t;
  inp(t);

  while (t--) {
    inp(n);

    for (int i = 0; i < 11; i++) {
      for (int j = 0; j < 101; j++){
        matrix[i][j] = false;
      }
    }

    for (int i = 1; i <= n; i++) {
      string line;
      getline(cin, line);
      istringstream this_line(line);
      istream_iterator<int> begin(this_line), end;
      vector<int> values(begin, end);
      for (int j = 0; j < values.size(); j++) {
        matrix[i][values[j]] = true;
      }
    }

    for (int i = 0; i < 1024; i++) {
      for (int j = 0; j < 101; j++) {
        dp[i][j] = -1;
      }
    }

    int ans = recurse((1<<n)-1,1);
    printf("%d\n",ans);
  }
}