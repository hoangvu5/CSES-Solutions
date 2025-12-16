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
    int n; T ID = 0; vector<T> seg;
    Seg(int n): n(n), seg(4*n, ID) {}
    T comb(T a, T b) { return a + b; }
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
};

void solve() {
    int n; cin >> n;
    vector<int> cnt(n, 1), arr(n);
    Seg<int> seg(n);
    seg.build(cnt, 1, 0, n - 1);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        int idx = seg.check(1, 0, n - 1, x);
        cout << arr[idx] << ' ';
        seg.update(1, 0, n - 1, idx, 0);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}