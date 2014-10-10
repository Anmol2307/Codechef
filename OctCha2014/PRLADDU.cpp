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
typedef long long int lli;
typedef pair<lli,int> pli;

int main () {
  int t;
  inp(t);

  while (t--) {
    int n;
    inp(n);

    vector <pli> pos;
    vector <pli> neg;

    for (int i = 0; i < n; i++) {
      lli x;
      scanf("%lli", &x);
      if (x >= 0) pos.push_back(pli(x,i));
      else neg.push_back(pli(-x,i));
    }

    lli ans = 0;
    int i = 0, j = 0;
    while (j < pos.size() && i < neg.size()) {
        if (pos[j].first == neg[i].first) {
          ans += (lli)abs(pos[j].second - neg[i].second)*pos[j].first;
          // printf("One %lli %lli %lli\n",ans, neg[i].first, pos[j].first);
          i++; j++;
        }
        else if (pos[j].first > neg[i].first) {
          ans += (lli)abs(pos[j].second - neg[i].second)*neg[i].first;
          pos[j].first -= neg[i].first;
          // printf("Two %lli %lli %lli\n",ans, neg[i].first, pos[j].first);
          i++;
        }
        else {
          ans += (lli)abs(pos[j].second - neg[i].second)*pos[j].first;
          neg[i].first -= pos[j].first;
          // printf("Three %lli %lli %lli\n",ans, neg[i].first, pos[j].first);
          j++;
        }
    }

    printf("%lli\n",ans);

  }
}