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
  int n;
  inp(n);
  
  int arr[5][101];
  memset(arr,0,sizeof(arr));

  for (int i = 0; i < n; i++) {
    char ch; int marks;
    cin >> ch >> marks;
    arr[ch-'A'][marks]++;
  }

  for (int i = 0; i < 5; i++) {
    int total = 0;
    bool flag = false;
    for (int j = 0; j <= 100; j++) {
      total += arr[i][j];
    }
    for (int j = 0; j <= 100; j++) {
      if ((double)(double(arr[i][j])/double(total)) > 0.1) {
        printf("%d ",j);
        flag = true;
      }
    }
    if (!flag) printf("Nothing Unusual");
    printf("\n");
  }
}