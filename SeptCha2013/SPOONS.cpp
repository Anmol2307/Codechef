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

typedef unsigned long long llu;

llu C[65];

void pre()
{
  C[0] = 1;
  C[1] = 1;
  long long int prev = 1;
  for(long long int i=2;i<=64;i++)
  {
    C[i]=C[i-1];
    if(i%2==1)
    {
      C[i]/=prev;
      C[i]*=i;
    }
    else
    {
      C[i]*=2;
      prev = i/2 + 1;
    }
  }
}

int binSearch (llu n) {
  int low = 0, high = 64;

  while (low <= high) {
    int mid = low + (high - low)/2;
    if (C[mid] < n && C[mid+1] >= n) return mid+1;  
    if (C[mid] < n) low = mid + 1;
    else high = mid - 1;
    // printf("%d %d\n",low,high);
  }
  return -1;
}

int main () {
  int t;
  inp(t);
  pre();

  while (t--) {
    llu n;
    scanf("%lli",&n);

    // for (int i = 0; i < 65; i++) {
    //   printf("%lli ",C[i]);
    // }
    // exit(0);
    int ans = binSearch(n);
    // int ans = 0;
    // for(int i=1;i<=64;i++){
    //    if(C[i]>=n){
    //      ans = i;
    //      break;
    //   }
    // }
    printf("%d\n",ans);
  }
}