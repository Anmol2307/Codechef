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

#define N 100000
typedef long long ll;

struct node {
  int maxval;
  ll sum;
  int inc;
  int dec;
  int first;
  int last;
  // node():val(0){}
  void init (int s) {
    maxval= s;
    sum = s;
    inc = 1;
    dec = 1;
    first = s;
    last = s;
  }

  void merge (node &l, node &r) {
    maxval = max(l.maxval,r.maxval);
    sum = l.sum + r.sum;
    if (l.inc && r.inc && r.first >= l.last) {
      inc = 1;
    }
    else inc = 0;
    if (l.dec && r.dec && r.first <= l.last) {
      dec = 1;
    }
    else dec = 0;
    first = l.first;
    last = r.last;
  }
}tree[4*N + 10];;

int arr[N+5];


node combineNode(node &l, node &r) {
    node n;
    n.maxval = max(l.maxval,r.maxval);
    n.sum = l.sum + r.sum;
    if (l.inc && r.inc && r.first >= l.last) {
      n.inc = 1;
    }
    else n.inc = 0;
    if (l.dec && r.dec && r.first <= l.last) {
      n.dec = 1;
    }
    else n.dec = 0;
    n.first = l.first;
    n.last = r.last;
    return n;
}

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


void update_tree(int node, int a, int b, int i, int j, int value) {
    
 if(a > b || a > j || b < i)
   return;
    
    if(a == b) {
      arr[a] = value;
      tree[node].init(arr[a]);
      return;
    }
 
 update_tree(node*2, a, (a+b)/2, i, j, value);
 update_tree(1+node*2, 1+(a+b)/2, b, i, j, value);
 
 tree[node].merge(tree[node*2], tree[node*2+1]);
}

node query_tree(int node, int a, int b, int i, int j) {
  
  if (a==i && b==j) return tree[node];
  int mid = (a+b)/2;
    if (j <= mid) {
        return query_tree((node<<1), a, mid, i, j);
    }
    if (i > mid) {
        return query_tree((node<<1) + 1, mid+1,b,i,j);
    }
    struct node left = query_tree((node<<1), a, mid, i, mid);
    struct node right = query_tree((node<<1) + 1, mid+1,b ,mid+1,j);
    return combineNode(left,right);
}



// void print_tree () {
//   int last = 1<<(x+2) - 1;
//   for (int i = 1; i < last; i++) {
//     printf("%d %d\n",tree[i].open, tree[i].close);
//   }
// }


int main () {

  int t = 1;

  while (t--) {
    int n, m;
    inp(n); inp(m);

    for (int i = 0; i < n; i++) {
      inp(arr[i]);
    }
    build_tree(1,0,n-1);

    for (int i = 0; i < m; i++) {
      char type;
      cin >> type;

      if (type == 'U') {
        int x, d;
        inp(x); inp(d);
        update_tree(1,0,n-1,x-1,x-1,d);
      }
      else if (type == 'M') {
        int x, y;
        inp(x); inp(y);
        printf("%d\n",query_tree(1,0,n-1,x-1,y-1).maxval);
      }
      else if (type == 'S') {
        int x, y;
        inp(x); inp(y);
        printf("%lli\n",query_tree(1,0,n-1,x-1,y-1).sum);
      }
      else if (type == 'I') {
        int x, y;
        inp(x); inp(y);
        printf("%d\n",query_tree(1,0,n-1,x-1,y-1).inc);
      }
      else if (type == 'D') {
        int x, y;
        inp(x); inp(y);
        printf("%d\n",query_tree(1,0,n-1,x-1,y-1).dec);
      }
    }
  }
}