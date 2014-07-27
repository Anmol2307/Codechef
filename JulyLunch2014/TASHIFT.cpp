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
#define mm 1000000
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

char arr[mm];
char brr[mm];

int main () {

  int n;
  inp(n);
  scanf("%s",arr);
  scanf("%s",brr);
  string strSample(brr);
  // printf("%s\n",strSample.c_str());
  // exit(0);
  const char chCharToSearch = arr[0];
  size_t nCharacterOffset = strSample.find (chCharToSearch, 0);
  // printf("%lu\n",nCharacterOffset);
  int supermax = -1;
  int ans = 0; 
  while (nCharacterOffset != string::npos)
  {
    int max = 1;int j = 1;
    for (int i = nCharacterOffset+1;j < n; i++) {
      if (i==n) i = 0;
      if (brr[i] == arr[j++]) {
        max++;
      }
      else break;
    }
    // printf("HERE %d\n",j,);
    if (supermax < max) {
      supermax = max;
      ans = nCharacterOffset;
    }
    size_t nCharSearchOffset = nCharacterOffset + 1;
    nCharacterOffset = strSample.find(chCharToSearch,nCharSearchOffset);
  }
  printf("%d\n",ans);
}