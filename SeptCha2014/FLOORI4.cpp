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

typedef long long int LL;
typedef unsigned long long llu;
llu n, m;


llu find (llu st) {
    int nm = 30*m;
    LL start = (((st%nm)*(st%nm))+ st)%nm;
    start = (start*((2*(st%nm))+1))%nm;
    LL a = ((3*((st%nm)*(st%nm))) + (3*st) - 1);
    if (a < 0) a += nm;
    start = (start*a)%nm;
    start /= 30;
    return start;
}

llu findSum(llu st, llu en) {
    LL diff = (find(en) - find(st));
    if (diff < 0) diff += m;
    return diff;
}


int main () {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%llu %llu\n", &n, &m);
        llu cnt = 0;
        for(llu i=1; i<=n; ) {
            llu val = n/i;
            llu nxt = n/val+1;
            cnt = (cnt + ((val%m)*findSum(i-1,nxt-1))%m)%m;
            i = nxt;
        }
        printf("%llu\n", cnt);
    }
}   
