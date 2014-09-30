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

typedef pair<int,int> pii;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vii;
typedef priority_queue<pii, vpii, greater<pii> > pqii;

#define INF (1<<30)
#define N 1000001

lli modpow(lli base, lli exp, lli modulus) {
  base %= modulus;
  lli result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
 
lli modInverse(lli a, lli m) {
    return modpow(a,m-2,m);
}



int main () {
  int t;
  inp(t);

  while (t--) {
    lli x, m, n;
    scanf("%lli %lli %lli", &x, &m, &n);
    lli first = modpow(x,m+1,n);
    first -= 1;
    if (first < 0) first += n;
    lli second = modInverse(x-1,n);
    lli ans = (first*second)%n;
    printf("%lli\n",ans);
  }
}
