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


int main () {

  int count = 0;
  for (int i = 1; i <= 100; i++) {
    if ((i*i*i) % 31 == 1) {
      printf("%d\n",i*i*i);
      count++;
    }
  }
  printf("%d\n\n",count);

  for (int i = 1; i <= 31; i++) {
    if ((i*i*i) % 31 == 1) {
      printf("%d\n",i*i*i);
      count++;
    }
  }

}