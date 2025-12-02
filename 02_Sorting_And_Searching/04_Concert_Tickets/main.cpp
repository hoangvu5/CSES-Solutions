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

void solve() {
    int n, m; cin >> n >> m;
    multiset<int> h;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        h.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int t; cin >> t;
        auto it = h.upper_bound(t);
        if (it == h.begin()) {
            cout << -1 << '\n';
            continue;
        }
        cout << *(--it) << '\n';
        h.erase(it);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}