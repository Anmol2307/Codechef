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

vector <pii>  vec;
vector <pii> segs;
  
int Floor(int key)
{
    int l = 0, r = segs.size(), m;
 
    while( r - l > 1 )
    {
        m = l + (r - l)/2;
 
        if( segs[m].first <= key )
            l = m;
        else
            r = m;
    }
 
    return l;
}


int main () {
  int n, k;
  inp(n); inp(k);

  int arr[n];
  for (int i = 0; i < n; i++) {
    inp(arr[i]);
  }

  for (int i = 0; i < k ; i++) {
    int x, y;
    inp(x); inp(y);
    vec.push_back(pii(x,y));
  }

  sort(vec.begin(), vec.end());
  segs.push_back(vec[0]);
  int i = 0;

  for (int j = 1; j < k; j++) {
    if (vec[j].first <= segs[i].second) {
      if (vec[j].second > segs[i].second) segs[i].second = vec[j].second;
    }
    else {
      segs.push_back(vec[j]);
      i++;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] >= segs[0].first) {
      int ind = Floor(arr[i]);  
      if (segs[ind].first <= arr[i] && segs[ind].second >= arr[i]) ans++;
    }
  }
  printf("%d\n",ans);
}
