#include"cstdio"
#include"cassert"
#include"cstring"
#define bound(a, b, c) ( ((a)>=(b)) and ((a)<=(c)) )
void solve() {
    int n;
    scanf("%d", &n);
    assert(bound(n, 1, 50));
    int a[n], b[n], p[n];
    for(int i=0; i<n; i++)
        scanf("%d%d%d", &p[i], &a[i], &b[i]), assert(bound(a[i], 1, 16)  and bound(b[i], 1, 16) and bound (p[i], 0, 100));
    if(n>16) { printf("0\n"); return; }
    double ans = 0;
    for(int i=0; i<(1<<n); i++) {
        char cnt[17], ind=0;
        double mlt = 1;
        memset(cnt, 0, 17);
        for(int j=0; j<n and ind==j; j++)
        {
            int x, pr;
            if(i&(1<<j))
                x = b[j], pr=100-p[j];
            else
                x = a[j], pr=p[j];
            ind += (not (cnt[x]++))?1:0;
            mlt *= pr/100.0;
        }
        if(ind==n)
            ans += mlt;
    }
    printf("%.9lf\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    assert(bound(T, 1, 10));
    while(T--) solve();
}
