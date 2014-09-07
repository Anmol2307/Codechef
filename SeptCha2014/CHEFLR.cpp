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

#define MOD 1000000007

int main () {
  int n;
  inp(n);
  char ch[100005];
  for (int i = 0; i < n; i++) {
    scanf("%s",ch);
    int len = strlen(ch);
    long long int ans = 1;
    for (int j = 0; j < len; j++) {
      // printf("%d %c ",j,ch[j]);
      if ((j & 1) == 0) {
        if (ch[j] == 'l') {
          ans = (ans*2)%MOD;          
        } 
        else {
          ans = ((ans*2)%MOD + 2)%MOD;
        }
      }
      else {
        if (ch[j] == 'l') {
          ans = ((ans*2)%MOD - 1);  
          if (ans < 0) ans += MOD;        
        }
        else {
          ans = ((ans*2)%MOD + 1)%MOD;
        }
      }
      // printf("%lli\n",ans);
    }
    printf("%lli\n",ans);
  }
}