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


int main () {
  int t;
  inp(t);

  while (t--) {
    int n;
    inp(n);
    vector <string> vec;
    for (int i = 0; i < n; i++) {
      string line;
      getline(cin,line);
      vec.push_back(line);
    }

    int dp[n][n];
    memset(dp,-1,sizeof(dp));
    
    for (int i = 0; i < n; i++) {
      for (int j = n-1; j >= 0; j--) {
        if (vec[i][j] == '.') {
          dp[i][j] = 1;
        }
        else {
          break;
        }
      }
    }

    for (int j = 0; j < n; j++) {
      for (int i = n-1; i >= 0; i--) {
        if (vec[i][j] == '.' && dp[i][j] == 1) {
          continue;
        }
        else if (vec[i][j] == '#') {
          while (i >= 0) {
            dp[i][j] = -1;
            i--;
          }
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dp[i][j] == 1) {
          ans++;
        }
      }
    }
    printf("%d\n",ans);
  }
}