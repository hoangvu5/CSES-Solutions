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
    int n; T ID = INT_MIN; vector<T> seg;
    Seg(int n): n(n), seg(4*n, ID) {}
    T comb(T a, T b) { return max(a, b); }
    void build(const vector<T> &arr, int v, int tl, int tr) {
        if (tl == tr) seg[v] = arr[tl];
        else {
            int tm = tl + (tr - tl) / 2;
            build(arr, v*2, tl, tm);
            build(arr, v*2+1, tm+1, tr);
            seg[v] = comb(seg[v*2], seg[v*2+1]);
        }
    }
    void update(int v, int tl, int tr, int pos, T x) {
        if (tl == tr && tl == pos) seg[v] = x;
        else {
            int tm = tl + (tr - tl) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, x);
            else
                update(v*2+1, tm+1, tr, pos, x);
            seg[v] = comb(seg[v*2], seg[v*2+1]);
        }
    }
    T query(int v, int tl, int tr, int l, int r) {
        if (l > r) return ID;
        if (l == tl && r == tr) return seg[v];
        int tm = tl + (tr - tl) / 2;
        return comb(query(v*2, tl, tm, l, min(r, tm)),
                    query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
    // Return min index i s.t pref[i] >= x
    // For sum tree
    int check(int v, int tl, int tr, T x) {
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
    int search(int v, int tl, int tr, int l, int r, T x) {
        if (tl > r || tr < l) return -1;
        if (seg[v] <= x) return -1;
        if (tl == tr) return tl;
        int tm = tl + (tr - tl) / 2;
        int left = search(v*2, tl, tm, l, r, x);
        if (left != -1) return left;
        return search(v*2+1, tm+1, tr, l, r, x);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    Seg<int> seg(n);
    seg.build(arr, 1, 0, n - 1);
    for (int i = 0; i < m; i++) {
        int r; cin >> r;
        int x = seg.search(1, 0, n - 1, 0, n - 1, r - 1);
        cout << x + 1 << ' ';
        if (x != -1) {
            int old = seg.query(1, 0, n - 1, x, x);
            seg.update(1, 0, n - 1, x, old - r);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}