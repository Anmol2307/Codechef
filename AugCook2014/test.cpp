#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define gc getchar_unlocked
 
vector<vector<int> > a;
vector<bool> vis;
vector<int> par;
set<pair<int,int>,greater<pair<int,int> > > s; 
int tot;
 
void go(int x, int pa, int l) {
  bool p = true;
  vis[x] = true;
  par[x] = pa;
  for(int i=0; i<a[x].size(); i++) {
    if(!vis[a[x][i]]) {
      p = false;
      go(a[x][i], x, l+1);
    }
  }
  if(p) {
    s.insert(make_pair(l,x));
  }
}
 
int main() {
  int t;
  scanf("%d",&t);
  while(t-->0) {
    int n;
    scanf("%d",&n);
    a.clear();
    a.resize(n+1);
    vis.clear();
    vis.resize(n+1);
    for(int i=1; i<=n; i++) vis[i] = 0;
    par.clear();
    par.resize(n+1);
    s.clear();
    for(int i=0; i<n-1; i++) {
      int x,y;
      scanf("%d%d",&x,&y);
      a[x].push_back(y);
      a[y].push_back(x);
    }
    go(1,0,1);
    int tot = 1;
    int l = 2;
    while(true) {
      if(s.size()==0 || s.begin()->first<l) break;
      tot++;
      pair<int,int> p = *s.begin();
      s.erase(s.begin());
      s.insert(make_pair(p.first-1,par[p.second]));
      if(s.size()>0 && s.begin()->first>=l) tot++;
      l++;
    }
    printf("%d\n",tot);
  }
  return 0;
}
 