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
    int ind[n], inv[n];
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ind[x - 1] = i;
        inv[i] = x - 1;
    }
    int cur = 1;
    for (int i = 1; i < n; i++) {
        cur += ind[i - 1] > ind[i];
    }
    for (int i = 0; i < m; i++) {
        int ia, ib; cin >> ia >> ib;
        int a = inv[--ia], b = inv[--ib];
        set<int> s = {a, b};
        if (a) s.insert(a - 1);
        if (b) s.insert(b - 1);
        if (n - 1 - a) s.insert(a + 1);
        if (n - 1 - b) s.insert(b + 1);

        for (int x : s) if (x) cur -= ind[x - 1] > ind[x];
        swap(ind[a], ind[b]);
        swap(inv[ia], inv[ib]);
        for (int x : s) if (x) cur += ind[x - 1] > ind[x];
        cout << cur << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}