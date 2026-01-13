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

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    map<int, int> ma;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ma[x]++;
    }
    int ans = 1;
    for (auto &[val, cnt] : ma) {
        ans = 1ll * ans * (cnt + 1) % MOD;
    }
    cout << (ans - 1) % MOD << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}