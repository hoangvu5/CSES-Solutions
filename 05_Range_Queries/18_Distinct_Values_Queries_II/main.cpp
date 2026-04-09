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
template <class I, class T> struct Seg {
    int n; T ID; vector<I> seg;
    Seg(int n): n(n), ID(n), seg(4*n, n) {}
    void comb(I& r, const I& a, const I& b) { r = min(a, b); }
    T ops(const T& a, const T& b) { return min(a, b); }
    void build(const vector<I> &arr, int v, int tl, int tr) {
        if (tl == tr) seg[v] = arr[tl];
        else {
            int tm = tl + (tr - tl) / 2;
            build(arr, v*2, tl, tm);
            build(arr, v*2+1, tm+1, tr);
            comb(seg[v], seg[v*2], seg[v*2+1]);
        }
    }
    void update(int v, int tl, int tr, int pos, const I& x) {
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
        if (l > r) return ID;
        if (l == tl && r == tr) return seg[v];
        int tm = tl + (tr - tl) / 2;
        return ops(query(v*2, tl, tm, l, min(r, tm)),
                    query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
    // Return min index i s.t pref[i] >= x
    // For sum tree
    int check(int v, int tl, int tr, const T& x) {
        if (x > seg[v]) return -1;
        if (tl == tr) return tl;
        int tm = tl + (tr - tl) / 2;
        if (seg[v*2] >= x)
            return check(v*2, tl, tm, x);
        else
            return check(v*2+1, tm+1, tr, x - seg[v*2]);
    }
    // Return min index i in [l, r] s.t a[i] > x
    // For max tree
    int search(int v, int tl, int tr, int l, int r, const T& x) {
        if (tl > r || tr < l) return -1;
        if (seg[v] <= x) return -1;
        if (tl == tr) return tl;
        int tm = tl + (tr - tl) / 2;
        int left = search(v*2, tl, tm, l, r, x);
        if (left != -1) return left;
        return search(v*2+1, tm+1, tr, l, r, x);
    }
};

unordered_map<int, set<int>> ma;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ma[arr[i]].insert(i);
    }
    Seg<int, int> seg(n);
    vector<int> nxt(n, n);
    for (auto &[val, se] : ma) {
        int prv = -1;
        for (auto &idx : se) {
            if (prv != -1) nxt[prv] = idx;
            prv = idx;
        }
    }
    seg.build(nxt, 1, 0, n - 1);

    int type, r;
    set<int>::iterator it;
    while (q--) {
        cin >> type;
        if (type == 1) {
            int k, u; cin >> k >> u; k--;
            auto& se = ma[arr[k]];
            it = se.find(k);
            r = (next(it) == se.end() ? n : *next(it));
            if (it != se.begin()) {
                seg.update(1, 0, n - 1, *prev(it), r);
            }
            se.erase(k);
            arr[k] = u;
            auto& ne = ma[arr[k]];
            ne.insert(k);
            it = ne.find(k);
            r = (next(it) == ne.end() ? n : *next(it));
            seg.update(1, 0, n - 1, k, r);
            if (it != ne.begin()) {    
                seg.update(1, 0, n - 1, *prev(it), k);
            }
        } else {
            int a, b; cin >> a >> b;
            a--; b--;
            int idx = seg.query(1, 0, n - 1, a, b);
            if (idx <= b) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

