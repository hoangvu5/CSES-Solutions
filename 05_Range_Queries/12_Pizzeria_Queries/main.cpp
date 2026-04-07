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

using Z = int;

template <class Info, class Tag> struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LazySegmentTree(int n = 0, const Info &v = {}) { init(n, v); }
    void init(int n, const Info &v = {}) { init(std::vector(n, v)); }
    void init(const std::vector<Info> &a) {
        n = a.size();
        if (n == 0) return;
        info.assign(4 << std::__lg(n), {});
        tag.assign(4 << std::__lg(n), {});
        auto dfs = [&](auto &&self, int p, int l, int r) -> void {
            if (r - l == 1) {
                info[p] = a[l];
                return;
            }
            int m = (l + r) / 2;
            self(self, 2 * p, l, m);
            self(self, 2 * p + 1, m, r);
            pull(p);
        };
        dfs(dfs, 1, 0, n);
    }
    void pull(int p) { // change to other communicative ops
        info[p] = min(info[2 * p], info[2 * p + 1]);
    }
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = {};
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) { info[p] = v; return; }
        push(p);
        int m = (l + r) / 2;
        if (x < m) modify(2 * p, l, m, x, v);
        else modify(2 * p + 1, m, r, x, v);
        pull(p);
    }
    void modify(int x, const Info &v) { modify(1, 0, n, x, v); }
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) return;
        if (l >= x && r <= y) { apply(p, v); return; }
        push(p);
        int m = (l + r) / 2;
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag &v) {
        rangeApply(1, 0, n, l, r, v);
    }
    Info query(int p, int l, int r, int x) {
        if (r - l == 1) {
            return info[p];
        }
        push(p);
        int m = (l + r) / 2;
        if (x < m) return query(2 * p, l, m, x);
        else return query(2 * p + 1, m, r, x);
    }
    Info query(int x) { return query(1, 0, n, x); }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return {};
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        push(p);
        int m = (l + r) / 2;
        Info lhs = rangeQuery(2 * p, l, m, x, y);
        Info rhs = rangeQuery(2 * p + 1, m, r, x, y);
        return min(lhs, rhs);
    }
    Info rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }
    template <class F> int findFirst(int p, int l, int r, int x, int y, const F &pred) {
        if (l >= y || r <= x || !pred(info[p])) return -1;
        if (r - l == 1) return l;
        push(p);
        int m = (l + r) / 2;
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) res = findFirst(2 * p + 1, m, r, x, y, pred);
        return res;
    }
    template <class F> int findFirst(int l, int r, const F &pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template <class F> int findLast(int p, int l, int r, int x, int y, const F &pred) {
        if (l >= y || r <= x || !pred(info[p])) return -1;
        if (r - l == 1) return l;
        push(p);
        int m = (l + r) / 2;
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) res = findLast(2 * p, l, m, x, y, pred);
        return res;
    }
    template <class F> int findLast(int l, int r, const F &pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};

struct Tag {
    Z k, b;
    Tag(Z k = 1, Z b = 0) : k{k}, b{b} {}
    void apply(const Tag &v) {
        k *= v.k;
        b *= v.k;
        b += v.b;
    }
};

struct Info {
    Z x;
    Info(Z x = 1e9) : x{x} {} // change default
    void apply(const Tag &v) {
        x = x * v.k + v.b;
    }
};

bool operator<(const Info &lhs, const Info &rhs) { // change ops
    return lhs.x < rhs.x;
};

// Price pizza from a to b = p[a] + abs(a - b)
// Update price of pizza in a building
// Order pizza price
// Point update min range query

void solve() {
    int n, q; cin >> n >> q;
    vector<int> price(n);
    for (int i = 0; i < n; i++) cin >> price[i];
    int type, k, x;
    LazySegmentTree<Info, Tag> pos(n, {0}), neg(n, {0});
    for (int i = 0; i < n; i++) {
        pos.modify(i, {i + price[i]});
        neg.modify(i, {-i + price[i]});
    }
    while (q--) {
        cin >> type >> k;
        k--;
        if (type == 1) {
            int x; cin >> x;
            price[k] = x;
            pos.modify(k, {k + price[k]});
            neg.modify(k, {-k + price[k]});
        } else {
            int left = k + neg.rangeQuery(0, k).x;
            int right = -k + pos.rangeQuery(k, n).x;
            cout << min(left, right) << '\n';
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}