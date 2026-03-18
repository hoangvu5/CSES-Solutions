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

struct Line {
    ll m, b;
    ll eval(ll x) { return m * x + b; }
};

// Intersection: (b_i - b_j) / (m_j - m_i)
// Bad if l1 and l3 intersects to the left of l1 and l2
bool bad(const Line& l1, const Line& l2, const Line& l3) {
    return (__int128)(l3.b - l1.b) * (l1.m - l2.m) <= (__int128)(l2.b - l1.b) * (l1.m - l3.m);
}

void solve() {
    int n; ll m; cin >> n >> m;
    vector<Line> lines(n);
    for (int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        lines[i] = {b - a, a * m}; // stores everything times m
    }
    sort(lines.begin(), lines.end(), [&](const Line& a, const Line& b) {
        return a.m != b.m ? a.m < b.m : a.b > b.b;
    });
    vector<Line> hull;
    for (auto &l : lines) {
        if (!hull.empty() && hull.back().m == l.m) continue; // skip line same slope
        while (hull.size() > 1 && bad(hull[hull.size()-2], hull.back(), l)) {
            hull.pop_back();
        }
        hull.push_back(l);
    }
    int ptr = 0;
    for (int i = 0; i <= m; i++) {
        while (ptr + 1 < hull.size() && hull[ptr+1].eval(i) >= hull[ptr].eval(i)) {
            ptr++;
        }
        cout << hull[ptr].eval(i) / m << ' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}