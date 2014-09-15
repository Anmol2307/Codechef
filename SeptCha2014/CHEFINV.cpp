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
  
#define N 200003
typedef long long int lli;

lli arr[N];
lli tree[400007];
lli lazy[400007];

 
void build_tree(int node, int a, int b) {
    if(a > b) return; // Out of range
    
    if(a == b) { // Leaf node
      tree[node] = arr[a]; // Init value
    return;
  }
  
  build_tree(node*2, a, (a+b)/2); // Init left child
  build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
  
  tree[node] = tree[node*2] + tree[node*2+1]; // Init root value
}
 
/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j) {
    

  if(a > b || a > j || b < i) // Current segment is not within range [i, j]
    return;
    
    if(a == b) { // Leaf node
        tree[node] = sqrt(tree[node]);
        return;
  }
 
  update_tree(node*2, a, (a+b)/2, i, j); // Updating left child
  update_tree(1+node*2, 1+(a+b)/2, b, i, j); // Updating right child
 
  tree[node] = tree[node*2] + tree[node*2+1]; // Updating root with max value
}

void update_tree_lazy(int node, int a, int b, int i, int j) {
  
    if(lazy[node] != 0) { // This node needs to be updated
      tree[node] += lazy[node]; // Update it
 
    if(a != b) {
      lazy[node*2] += lazy[node]; // Mark child as lazy
        lazy[node*2+1] += lazy[node]; // Mark child as lazy
    }
 
      lazy[node] = 0; // Reset it
    }
  
  if(a > b || a > j || b < i) // Current segment is not within range [i, j]
    return;
    long long value = sqrt(tree[node]);
    if(a >= i && b <= j) { // Segment is fully within range
        tree[node] = value;
 
    if(a != b) { // Not leaf node
      lazy[node*2] = value;
      lazy[node*2+1] = value;
    }
 
        return;
  }
 
  update_tree(node*2, a, (a+b)/2, i, j); // Updating left child
  update_tree(1+node*2, 1+(a+b)/2, b, i, j); // Updating right child
 
  tree[node] = tree[node*2] + tree[node*2+1]; // Updating root with max value
}
 
/**
 * Query tree to get max element value within range [i, j]
 */
lli query_tree(int node, int a, int b, int i, int j, int val) {
  
    if (a==i && b==j) return tree[node];
    int mid = (a+b)/2;
    if (j <= mid) {
        return query_tree((node<<1), a, mid, i, j);
    }
    if (i > mid) {
        return query_tree((node<<1) + 1, mid+1,b,i,j);
    }
    long long l = query_tree((node<<1), a, mid, i, mid,val);
    long long r = query_tree((node<<1) + 1, mid+1,b ,mid+1,j,val);
    return l+r;

}

long long query_tree_lazy(int node, int a, int b, int i, int j) {
  
  if(a > b || a > j || b < i) return 0; // Out of range
 
  if(lazy[node] != 0) { // This node needs to be updated
    tree[node] += lazy[node]; // Update it
 
    if(a != b) {
      lazy[node*2] += lazy[node]; // Mark child as lazy
      lazy[node*2+1] += lazy[node]; // Mark child as lazy
    }
 
    lazy[node] = 0; // Reset it
  }
 
  if(a >= i && b <= j) // Current segment is totally within range [i, j]
    return tree[node];

  int mid = (a+b)/2;
    if (j <= mid) {
        return query_tree((node<<1), a, mid, i, j);
    }
    if (i > mid) {
        return query_tree((node<<1) + 1, mid+1,b,i,j);
    }
    long long l = query_tree((node<<1), a, mid, i, mid);
    long long r = query_tree((node<<1) + 1, mid+1,b ,mid+1,j);
    return l+r;
}


int main() {
  int n, m;
  inp(n); inp(m);
  
  for(int i = 0; i < n; i++) {
    scanf("%lli",&arr[i]);
  }
   
  build_tree(1, 0, n-1);
  for (int i=0; i < m; i++) {
    int x, y;
    inp(x);inp(y);
    x--,y--;
    if(x > y) swap(x, y);
    int val1 = query_tree(1, 0, n-1, x+1, y,arr[x]);
    int val2 = query_tree(1, 0, n-1, x, y-1,arr[y]);
  }
}