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

#define N 1000005

vector<int> pfactors[N];
vector <int> primes;
int prime[N];
int arr[N];
int calc[N];
int last[N];
int dp[N];
    
void find_prime_sieve() {
  for (int i = 2; i*i < N; i++) {
    if (prime[i] == 0) {
      for (int j = i*i; j < N; j += i) {
        prime[j] = 1;
      }
    }
  }

  for (int i = 2; i < N; i++) {
    if  (prime[i] == 0) primes.push_back(i);
  }
}

void calulate_prime_factors () {
  for(int i=2; i<=1000000; i++) {
    int j=i;
    for(int k=0; primes[k]*primes[k]<=j; k++) {
      if(j%primes[k]==0){
        pfactors[i].push_back(primes[k]);
        while(j%primes[k]==0)j/=primes[k];
      }
    }
    if(j>=2)pfactors[i].push_back(j);
  }
}

int main () {
  find_prime_sieve();
  calulate_prime_factors();
  int t;
  inp(t);
  
  while (t--) {
    memset(dp,-1,sizeof(dp));
    memset(calc,-1,sizeof(calc));
    memset(last,-1,sizeof(last));
    int n;
    inp(n);
    
    for (int i = 0; i < n; i++) {
      inp(arr[i]);
    } 
  
    for (int i = 0; i < pfactors[arr[0]].size(); i++) {
      last[pfactors[arr[0]][i]] = 0;
    }
    
    for (int i = 1; i < n; i++) {
      int ma = -1;
      for (int j = 0; j < pfactors[arr[i]].size(); j++) {
        ma = max(ma,last[pfactors[arr[i]][j]]);
        last[pfactors[arr[i]][j]] = i;
      }
      calc[i] = ma;
    }
    int ans = 0; 
    dp[0] = 1;
    
    for (int i = 1; i < n; i++) {
      dp[i] = min(dp[i-1] + 1,i-calc[i]);
      ans = max(ans,dp[i]);
    }

    if (ans == 1) printf("%d\n",-1);
    else printf("%d\n",ans);
  }
}