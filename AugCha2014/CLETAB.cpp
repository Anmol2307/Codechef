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
int * table;
int * arr;
int n,m;
bool contains (int elem) {
  for (int i = 0; i < n; i++) {
    if (table[i]==elem) {
      return true;
    }
  }
  return false;
}

int findSeat (int place) {
  map<int,int> mymap;
  int notPresent = -1;
  
  for (int i = 0; i < n; i++) {
    bool p=false;
    for (int j = place+1; j < m; j++) {
      if (arr[j] == table[i]) {
        if (!p) p = true;
        if (mymap.count(i) == 0) {
          mymap[i] = j;
          break;
        }
      }
    }
    if (!p) notPresent = i;
  }

  map<int,int>::iterator it;
  int maxindex = -1;
  int max = -1;
  if (notPresent == -1) {
    for (it = mymap.begin(); it != mymap.end(); it++) {
      if (it->second > max) {
        maxindex = it->first;
        max = it->second;
      }
    }
    return maxindex;
  }
  else {
    return notPresent;
  }
}

int main () {
  int t;
  inp(t);

  while (t--) {
    inp(n);inp(m);
    arr = new int[m];
    table = new int[n];
    int ans = 0;
    int seats = 0;
    for (int i = 0; i < m ; i++) {
      inp(arr[i]);
    }
    for (int i = 0; i < m; i++) {
      if (!contains(arr[i]) && seats < n) {
        ans++;
        table[seats++] = arr[i];
      }
      else if (!contains(arr[i])) {
        int s = findSeat(i);
        // printf("%d %d\n",i,s);
        // exit(0);
        ans++;
        table[s]=arr[i];
      }
    }
    // for (int i = 0; i < n; i++) {
    //   printf("%d ",table[i]);
    // }
    // printf("\n");
    printf("%d\n",ans);
  }
}