#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

struct Seg {
    int n;
    vector<int> flat;     // all sorted arrays concatenated
    vector<int> pos;      // pos[v] = start index in flat for node v
    vector<int> len;      // len[v] = size of node v's array

    Seg(int n) : n(n), pos(4*n, 0), len(4*n, 0) {}

    void build(const vi& arr, int v, int tl, int tr) {
        len[v] = tr - tl + 1;
        pos[v] = flat.size();
        flat.resize(flat.size() + len[v]);

        if (tl == tr) {
            flat[pos[v]] = arr[tl];
            return;
        }
        int tm = tl + (tr - tl) / 2;
        build(arr, v*2, tl, tm);
        build(arr, v*2+1, tm+1, tr);
        // merge children directly into pre-allocated space
        merge(flat.begin() + pos[v*2],   flat.begin() + pos[v*2]   + len[v*2],
              flat.begin() + pos[v*2+1], flat.begin() + pos[v*2+1] + len[v*2+1],
              flat.begin() + pos[v]);
    }

    int query(int v, int tl, int tr, int l, int r, int lo, int hi) {
        if (l > r) return 0;
        if (l == tl && r == tr) {
            auto base = flat.begin() + pos[v];
            auto L = lower_bound(base, base + len[v], lo);
            auto R = upper_bound(base, base + len[v], hi);
            return R - L;
        }
        int tm = tl + (tr - tl) / 2;
        return query(v*2,   tl,   tm, l,          min(r, tm), lo, hi) +
               query(v*2+1, tm+1, tr, max(l,tm+1), r,         lo, hi);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vi arr(n);
    for (auto& x : arr) cin >> x;

    Seg seg(n);
    seg.flat.reserve(n * 20); // reserve ~n log n space upfront
    seg.build(arr, 1, 0, n-1);

    int a, b, c, d;
    while (q--) {
        cin >> a >> b >> c >> d;
        a--; b--;
        cout << seg.query(1, 0, n-1, a, b, c, d) << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}