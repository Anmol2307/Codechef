#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <cctype>
#include <list>
#include <stack>
#include <fstream>
#include <utility>
#include <iomanip>
#include <climits>
using namespace std;

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}

// Node class
class Node {
public:
    Node() { mData = -1; mParent = NULL; mLeft = NULL; mRight = NULL; }
    ~Node() {}
    int data() { return mData; }
    void setData(int data) { mData = data; }
    Node* left() { return mLeft; }
    void setLeft(Node* left) { mLeft = left; }
    Node* right() { return mRight; }
    void setRight(Node* right) { mRight = right; }
    Node* parent() { return mParent; }
    void setParent(Node* parent) { mParent = parent; }
private:
    int mData;
    Node* mLeft;
    Node* mRight;
    Node* mParent;
};

// Tree class
class Tree {
public:
    Tree() { mRoot = NULL; }
    ~Tree() {}
    Node* root() { return mRoot; }
    void addNode(int data);
    Node* lca(Node* node, int data1, int data2);

private:
    void addNode(Node* node, int data);

private:
    Node* mRoot;
};

void Tree::addNode(int data) {
    if ( mRoot == NULL ) {
        Node* tmp = new Node();
        tmp->setData(data);
        mRoot = tmp;
    }
    else {
        addNode(mRoot, data);
    }
}

void Tree::addNode(Node* node, int data) {
    if ( data <= node->data() ) {
        if ( node->left() != NULL )
            addNode(node->left(), data);
        else {
            Node* tmp = new Node();
            tmp->setData(data);
            tmp->setParent(node);
            node->setLeft(tmp);
        }
    }
    else {
        if ( node->right() != NULL )
            addNode(node->right(), data);
        else {
            Node* tmp = new Node();
            tmp->setData(data);
            tmp->setParent(node);
            node->setRight(tmp);
        }
    }
}

Node* Tree::lca(Node* node, int data1, int data2) {
    if ( node ) {
        int data = node->data();
        if ( data1 < data && data2 > data )
            return node;
        else if ( data1 > data && data2 > data )
            return lca(node->right(), data1, data2);
        else
            return lca(node->left(), data1, data2);
    }
    return NULL;
}

// // Test program
// int main() {
//     Tree* t = new Tree();
//     t->addNode(500);
//     t->addNode(300);
//     t->addNode(600);
//     t->addNode(550);
//     t->addNode(700);
//     t->addNode(750);
//     t->addNode(200);
//     t->addNode(150);
//     t->addNode(250);
//     t->addNode(350);
//     t->addNode(800);

//     cout << t->lca(t->root(), 150, 350)->data() << endl;

//     delete t;
// }

int main () {
    int n;
    inp(n);
    Tree* t = new Tree();
    for (int i = 0; i < n-1; i++) {
        int x,y;
        inp(x); inp(y);
        t->addNode(x);
        t->addNode(y);
    }
    int q;
    inp(q);

    for (int i = 0; i < q; i++) {
        int r, a, b;
        inp(r); inp(a); inp(b);
        // printf("HERE %d %d %d\n",t->root()->data(),a,b);
        // exit(0);
        cout << t->lca(t->root(), a, b)->data() << endl;    
    }
    delete t;
}