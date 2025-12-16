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

// 0-idx segment tree, PURQ
template <class T> struct Seg {
    int n; T ID = 0; vector<T> seg, pre;
    Seg(int n): n(n), seg(4*n, ID), pre(4*n, ID) {}
    pair<T, T> comb(pair<T, T> a, pair<T, T> b) {
        // {max prefix, sum}
        return {max(a.first, a.second + b.first), a.second + b.second};
    }
    void build(const vector<T> &arr, int v, int tl, int tr) {
        if (tl == tr) {
            seg[v] = arr[tl];
            pre[v] = max(arr[tl], ID);
        } else {
            int tm = tl + (tr - tl) / 2;
            build(arr, v*2, tl, tm);
            build(arr, v*2+1, tm+1, tr);
            auto pa = comb({pre[v*2], seg[v*2]}, {pre[v*2+1], seg[v*2+1]});
            pre[v] = pa.first;
            seg[v] = pa.second;
        }
    }
    void update(int v, int tl, int tr, int pos, T x) {
        if (tl == tr && tl == pos) {
            seg[v] = x;
            pre[v] = max(x, ID);
        } else {
            int tm = tl + (tr - tl) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, x);
            else
                update(v*2+1, tm+1, tr, pos, x);
            auto pa = comb({pre[v*2], seg[v*2]}, {pre[v*2+1], seg[v*2+1]});
            pre[v] = pa.first;
            seg[v] = pa.second;
        }
    }
    pair<T, T> query(int v, int tl, int tr, int l, int r) {
        if (l > r) return {ID, ID};
        if (l == tl && r == tr) return {pre[v], seg[v]};
        int tm = tl + (tr - tl) / 2;
        pair<T, T> left = query(v*2, tl, tm, l, min(r, tm));
        pair<T, T> right = query(v*2+1, tm+1, tr, max(l, tm+1), r);
        return comb(left, right);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<ll> arr(n);
    Seg<ll> seg(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    seg.build(arr, 1, 0, n - 1);
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int k; ll u; cin >> k >> u;
            seg.update(1, 0, n - 1, --k, u);
        } else {
            int a, b; cin >> a >> b;
            a--, b--;
            cout << seg.query(1, 0, n - 1, a, b).first << '\n';
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}