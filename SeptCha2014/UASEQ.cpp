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
#define gc getchar_unlocked
void si(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

typedef long long int lli;

template<typename S, typename T>
bool operator<(const pair<S, T> & a, const pair<S, T> & b)
{
   return (a.first < b.first) || (a.first == b.first && a.second < b.second);
}

typedef pair<lli, lli> pll;
typedef pair<pll,int> ppi;

int main () {
  int n, k;
  si(n); si(k);

  int arr[n];
  map <pll, int> vec;
  si(arr[0]);
  for (lli i = 1; i < n; i++) {
    si(arr[i]);  
    lli d = arr[i] - arr[i-1];
    lli a = (arr[i] - i*d);
    vec.insert(ppi(pll(a,d),i-1));
  }
  map <pll, int>::iterator it;
  map <pll, int>::iterator e = vec.end();
  for (it = vec.begin(); it != e; it++) {
    lli a = (it->first).first; 
    lli d = (it->first).second;
    int val = 0;
    lli j = 0;
    for (; j < n; j++) {
      if ((a + j*d) != arr[j]) val++;
      if (val > k) break;
    }
    if (j == n) {
      for (lli k = 0; k < n; k++) {
        printf("%lli ",a+k*d);
      }
      printf("\n");
      break;
    }
  }
}