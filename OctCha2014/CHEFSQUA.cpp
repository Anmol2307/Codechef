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

typedef pair <double, double> pdd;

double mag(double a, double b) {
  return sqrt(a*a + b*b);
}

int main () {
  int n;
  inp(n);

  if (n == 0) {
    printf("4\n");
    return 0;
  }

  if (n == 1) {
    printf("3\n");
    return 0;
  }
  
  pdd arr[n];
  map<pdd, int> m;

  for (int i = 0; i < n; i++) {
    scanf("%lf %lf",&arr[i].first,&arr[i].second);
    m[arr[i]] = 1;
  }
  sort (arr,arr+n);

  int ans = 2;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      double x1 = arr[i].first;
      double y1 = arr[i].second;

      double x2 = arr[j].first;
      double y2 = arr[j].second;
      
      double dist = mag(x2-x1,y2-y1);
      // Case 1:

      double vx = -(y2-y1);
      double vy = x2-x1;
      double norm = mag(vx,vy);
      vx /= norm;
      vy /= norm;

      double x3 = x1 + dist*vx;
      double y3 = y1 + dist*vy;
      
      double x4 = x2 + dist*vx;
      double y4 = y2 + dist*vy;
      
      int a = 2;
      if (m.find(pdd(x3,y3)) != m.end()) a--;
      if (m.find(pdd(x4,y4)) != m.end()) a--;

      if (a == 0) {
        printf("0\n");
        return 0;
      }
      ans = min(a,ans);
      // Case 2:

      x3 = x1 - dist*vx;
      y3 = y1 - dist*vy;
      
      x4 = x2 - dist*vx;
      y4 = y2 - dist*vy;
      
      a = 2;
      if (m.find(pdd(x3,y3)) != m.end()) a--;
      if (m.find(pdd(x4,y4)) != m.end()) a--;

      if (a == 0) {
        printf("0\n");
        return 0;
      }
      ans = min(a,ans);
      // Case 3:

      double xc = (x1+x2)/2;
      double yc = (y1+y2)/2;

      double xd = (x1-x2)/2;
      double yd = (y1-y2)/2;

      x3 = xc - yd;
      y3 = yc + xd;
      
      x4 = xc + yd;
      y4 = yc - xd; 
      
      a = 2;
      if (m.find(pdd(x3,y3)) != m.end()) a--;
      if (m.find(pdd(x4,y4)) != m.end()) a--;

      if (a == 0) {
        printf("0\n");
        return 0;
      }
      ans = min(a,ans);
    }
  }
  printf("%d\n",ans);
}