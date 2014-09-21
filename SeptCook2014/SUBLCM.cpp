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

typedef unsigned long long lli;

lli gcd(lli a, lli b)  {
  lli t;
  if (a < b) swap(a,b);
  while (b) {
    t = a; 
    a = b;    
    b = t%b;   
  }
  return a;
}

lli lcm (lli a, lli b) {
  return (lli)((a*b)/(lli)gcd(a,b));
}

int prime[1000000];
vector <int> primes;

void sieve () {
  for (int i = 2; i*i < 1000000; i++) {
    if (!prime[i]) {
      for (int j = 2*i; j < 1000000; j+=i) {
        prime[j] = 1;
      }
    }
  }
  for (int i = 2; i < 1000000; i++) {
    if (!prime[i]) primes.push_back(i);
  }
}



int main () {
  int t;
  inp(t);

  while (t--) {
    int n;
    inp(n);

    lli arr[n];
    lli lc[n];
    int dp[n];
    // lli pro[n];
    for (int i = 0; i < n; i++) {
      scanf("%lli",&arr[i]);
    }
    
    // pro[0] = arr[0];
    // for (int i = 1; i < n; i++) {
    //   pro[i] = pro[i-1]*arr[i];
    // }
    
    dp[0] = 1;
    lc[0] = arr[0];
    int j = -1;
    lli p = 1;
    
    // for (int i = 0; i < n; i++) {
    //   printf("%lli ",pro[i]);
    // }
    // printf("\n");
    int max_ending_here = 1;
    int max_so_far = 1;
    for (int i = 1; i < n; i++) {
      lli val = lcm(arr[i],lc[i-1]);
      lli g = gcd(arr[i], lc[i-1]);
      if (g == 1) {
        max_ending_here++;
        lc[i] = val;
      }
      else {
        max_ending_here = 1;
        lc[i] = arr[i];
      }
      if (max_ending_here > max_so_far) max_so_far = max_ending_here;
    }


    if (max_so_far == 1) printf("-1\n");
    else printf("%d\n",max_so_far);


  }
}