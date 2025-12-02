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
    int x, n; cin >> x >> n;
    set<int> s;
    s.insert(0);
    s.insert(x);

    multiset<int, greater<int>> len;
    len.insert(x);
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        auto it = s.upper_bound(v);
        int r = *it, l = *(--it);
        s.insert(v);
        len.erase(len.find(r - l));
        len.insert(v - l);
        len.insert(r - v);
        cout << *len.begin() << ' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}