#include <bits/stdc++.h>
using namespace std;

int prime[31630];
vector <int> primes;

void sieve () {
  for (int i = 2; i*i < 31630; i++) {
    if (!prime[i]) {
      for (int j = 2*i; j < 31630; j+=i) {
        prime[j] = 1;
      }
    }
  }
  for (int i = 2; i < 31630; i++) {
    if (!prime[i]) primes.push_back(i);
  }
}


int main () {
  sieve();
  // for (int i = 0; i < primes.size(); i++) {
  //   printf("%d ",primes[i]);
  // }
  // printf("\n");
  // exit(0);
  int t;
  scanf("%d",&t);

  while (t--) {
    int l, r;
    scanf("%d %d",&l,&r);
    vector <int> ans ;
    for (int i = l; i <=r; i++) {
      int j = 0;
      bool flag = false;
      if (i==1) continue;
      while (primes[j]*primes[j] <= i && j < primes.size()) {
        if (i%primes[j] == 0) {
          flag = true;
          break;
        }
        j++;
      }
      if (!flag) ans.push_back(i);
    }
    for (int i = 0; i < ans.size(); i++) {
      printf("%d\n",ans[i]);
    }
    printf("\n");
  }
}