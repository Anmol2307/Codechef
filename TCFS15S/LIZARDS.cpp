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

#define N 80000

struct node {
  lli left;
  lli right;
  lli val;
  node(){
    left = 0;
    right = 0;
    val = 0;
  }
  void init (char s) {
    if (s == 'L') {
      left = 1;
    }
    else {
      right = 1;
    }
  }

  void merge (node &l, node &r) {
    val = l.right * r.left + l.val + r.val;
    left = l.left + r.left;
    right = l.right + r.right;
  }

}tree[4*N + 10];;

// int arr[N+5];
string arr;
int n;

void build_tree(int node, int a, int b) {
  if(a > b) return;
    
  if(a == b) { 
    tree[node].init(arr[a]);
    return;
  }

  build_tree(node*2, a, (a+b)/2); // Init left child
  build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
  tree[node].merge(tree[node*2], tree[node*2+1]);

}


void update_tree(int node, int a, int b, int i, int j) {
    
 if(a > b || a > j || b < i)
   return;
    
    if(a == b) {
      if(arr[a] == 'L') arr[a] = 'R';
      else if (arr[a] == 'R') arr[a] = 'L';
      tree[node].init(arr[a]);
      return;
    }
 
 update_tree(node*2, a, (a+b)/2, i, j);
 update_tree(1+node*2, 1+(a+b)/2, b, i, j);
 
 tree[node].merge(tree[node*2], tree[node*2+1]);
}


int main () {
  inp(n);
  string str;
  cin >> str;
  arr = str;
  build_tree(1,0,n-1);
  int q;
  inp(q);
  
  for (int i = 0; i < q; i++) {
    // arr = str;
    int x, y;
    inp(x); inp(y);
    update_tree(1,0,n-1,x,y);
    printf("%lli\n",tree[1].val);
    // for (int i = 1; i < 8; i++) {
    //   printf("%d %lli %lli %lli\n",i,tree[i].left,tree[i].right,tree[i].val);
    // }
  }
}