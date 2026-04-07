#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout<<#x<<" = "<<x<<'\n'
#define dbgv(x) for(int i=0;i<x.size();i++)cout<<x[i]<<' ';cout<<'\n'
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Info {
    ll pref, suff, sum, ans;
    Info() : pref(0), suff(0), sum(0), ans(0) {}
    Info(ll x) {
        sum = x;
        pref = suff = ans = max(x, 0ll);
    }
};

// 0-idx segment tree, PURQ
template <class T> struct Seg {
    int n; ll ID = 0; vector<T> seg;
    Seg(int n): n(n), seg(4*n, T{ID}) {}
    void comb(T& res, const T& a, const T& b) { 
        res.pref = max(a.pref, a.sum + b.pref);
        res.suff = max(b.suff, b.sum + a.suff);
        res.sum = a.sum + b.sum;
        res.ans = max({a.ans, b.ans, a.suff + b.pref});
    }
    void build(const vector<T> &arr, int v, int tl, int tr) {
        if (tl == tr) seg[v] = arr[tl];
        else {
            int tm = tl + (tr - tl) / 2;
            build(arr, v*2, tl, tm);
            build(arr, v*2+1, tm+1, tr);
            comb(seg[v], seg[v*2], seg[v*2+1]);
        }
    }
    void update(int v, int tl, int tr, int pos, const T& x) {
        if (tl == tr && tl == pos) seg[v] = x;
        else {
            int tm = tl + (tr - tl) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, x);
            else
                update(v*2+1, tm+1, tr, pos, x);
            comb(seg[v], seg[v*2], seg[v*2+1]);
        }
    }
    T query(int v, int tl, int tr, int l, int r) {
        if (l > r) return T{};
        if (l == tl && r == tr) return seg[v];
        int tm = tl + (tr - tl) / 2;
        Info res;
        comb(res, query(v*2, tl, tm, l, min(r, tm)),
             query(v*2+1, tm+1, tr, max(l, tm+1), r));
        return res;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<Info> arr(n, {0});
    ll x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr[i] = Info{x};
    }
    Seg<Info> seg(n);
    seg.build(arr, 1, 0, n - 1);
    int a, b;
    while (m--) {
        cin >> a >> b; a--; b--;
        cout << seg.query(1, 0, n - 1, a, b).ans << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}