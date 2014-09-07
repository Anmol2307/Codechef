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

bool pairCompare(const pair<int, int>& firstElem, const pair<int, int>& secondElem) {
  if (firstElem.first > secondElem.first) return true;
  else if (firstElem.first == secondElem.first && firstElem.second < secondElem.second) return true;
  else return false;
}

int main () {
  int t;
  inp(t);

  while (t--) {
    int n, k;
    inp(n); inp(k);

    pair <int,int> arr[n];

    for (int i = 0; i < n; i++) {
      inp(arr[i].first); inp(arr[i].second);
    }

    int ret = 0;
    for(int i = 0; i < (1 << n); i++) {
      int weight = 0, cost = 0; 
      for(int j = 0; j < n; j++){
        if (i & (1 << j)) { 
          weight += arr[j].second;
          cost += arr[j].first;
        }
      }
      if (cost <= k) ret = max(ret, weight); // if this set is affordable, we can consider it
    }
    printf("%d\n", ret); // output an answer
  }
}