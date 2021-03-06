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


int main () {
  int n,m,p;
  inp(n);inp(m);inp(p);
  vector <pair <int,int> > vec;
  for (int i = 0; i < p; i++) {
    int x, y;
    inp(x);inp(y);
    vec.push_back(pair<int,int>(x,y));
  }
  sort(vec.begin(),vec.end());
  // for (int i = 0; i < p; i++) {
  //   printf("%d %d\n",vec[i].first,vec[i].second);
  // }
  int j = 0;
  for (int i = 1; i <= n; i++) {
    if (vec[j].first == i) {
      vector <pair <int,int> > vp;
      while (vec[j].first == i) {
        int sec = vec[j].second;
        int count  = 0;
        while (vec[j].first == i && vec[j].second == sec) {
          j++;
          count++;
        }
        vp.push_back(pair<int,int>(sec,count));
      }
      int ans = m-1;
      bool flag = false;
      
      if (vp.size() == 1 && vp[0].second > 1) {
        printf("%d\n",-1);
        continue;
      }
      else if (vp.size() == 1 && vp[0].second <= 1) {
        printf("%d\n",ans);
        continue;
      }
      for (int k = 0; k < vp.size()-2; k++) {
        if (vp[k+1].first - vp[k].first == 1) {
          if (vp[k+1].second - vp[k].second >= -1) {
            ans += (vp[k+1].second -1 - vp[k].second);
          }
          else {
            printf("%d\n",-1);
            flag = true;
            break;
          }
        }
        else if (vp[k].second  > 1){
          printf("%d\n",-1);
          flag = true;
          break;
        }
      }
      ans += (vp[vp.size()-1].second -1);
      if (flag) continue;
      else printf("%d\n",ans);
    }
    else {
      printf("%d\n",m-1);
    }
  }
}