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

#define MOD 1000000009
typedef long long int lli;
typedef pair <lli, char> pii;

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


int main () {
  int t;
  inp(t);

  while (t--) {
    int n, m;
    inp(n); inp(m);

    pii arr[m];

    for (int i = 0; i < m; i++) {
      char ch; cin >> ch;
      arr[i].second = ch;
      scanf("%lli", &arr[i].first);
    }

    sort(arr, arr+m);
    lli val = 1;

    if (m > 1 && arr[0].second != arr[1].second) {
      val = val*(arr[1].first - arr[0].first);
    }
    for (int i = 1; i < m-1; i++) {
      // if (arr[i].second != arr[i-1].second) {
      //   val = val*(arr[i].first - arr[i-1].first)%MOD;
      // }
      if (arr[i].second != arr[i+1].second) {
        val = val*(arr[i+1].first - arr[i].first)%MOD;
      }
    }

    // if (m > 1 && arr[m-1].second != arr[m-2].second) {
    //   val = (val + arr[m-1].first - arr[m-2].first)%MOD;
    // }
    printf("%lli\n",val);
  }
}