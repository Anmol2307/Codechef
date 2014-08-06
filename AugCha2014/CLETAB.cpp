#include <iostream>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;


typedef long long int LL;


inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}

///////////////////////////////////////////////////////////////////////////////////////////
int * table;
int * arr;
int n,m;
bool contains (int elem) {
  for (int i = 0; i < n; i++) {
    if (table[i]==elem) {
      return true;
    }
  }
  return false;
}

int findSeat (int place) {
  map<int,int> mymap;
  int notPresent = -1;
  
  for (int i = 0; i < n; i++) {
    bool p=false;
    for (int j = place+1; j < m; j++) {
      if (arr[j] == table[i]) {
        if (!p) p = true;
        if (mymap.count(i) <= 0) {
          mymap[i] = j;
          break;
        }
      }
    }
    if (!p) notPresent = i;
  }

  map<int,int>::iterator it;
  int maxindex = -1;
  int max = -1;
  if (notPresent == -1 && mymap.size() != 0) {
    for (it = mymap.begin(); it != mymap.end(); it++) {
      if (it->second > max) {
        maxindex = it->first;
        max = it->second;
      }
    }
    return maxindex;
  } 
  else {
    return notPresent;
  }
  mymap.clear();
}

int main () {
  int t;
  inp(t);

  while (t--) {
    inp(n);inp(m);
    arr = new int[m];
    table = new int[n];
    int ans = 0;
    int seats = 0;
    for (int i = 0; i < m ; i++) {
      inp(arr[i]);
    }
    for (int i = 0; i < m; i++) {
      if (!contains(arr[i]) && seats < n) {
        ans++;
        table[seats++] = arr[i];
      }
      else if (!contains(arr[i])) {
        int s = findSeat(i);
        // printf("%d %d\n",i,s);
        // exit(0);
        ans++;
        table[s]=arr[i];
      }
    }
    // for (int i = 0; i < n; i++) {
    //   printf("%d ",table[i]);
    // }
    // printf("\n");
    printf("%d\n",ans);
  }
}