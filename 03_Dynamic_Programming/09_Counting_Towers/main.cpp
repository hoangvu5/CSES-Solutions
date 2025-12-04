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

const int m = 1e9 + 7;

void solve() {
    int t; cin >> t;
    vector<int> q(t);
    int n = 1;
    for (int i = 0; i < t; i++) {
        cin >> q[i];
        n = max(n, q[i]);
    }
    vector<array<int, 2>> dp(n);
    dp[0][0] = 1;
    dp[0][1] = 1;
    // 0: if blocks are not separated this level
    // 1: if blocks are separated this level
    for (int i = 1; i < n; i++) {
        dp[i][0] = (2ll * dp[i - 1][0] % m + dp[i - 1][1]) % m;
        dp[i][1] = (dp[i - 1][0] + 4ll * dp[i - 1][1] % m) % m;
    }
    for (int i = 0; i < t; i++) {
        cout << (dp[q[i] - 1][0] + dp[q[i] - 1][1]) % m << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}