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
    int n; cin >> n;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = (g[0][0] == '.');
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == '*') continue;
            if (i) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % m;
            if (j) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % m;
        }
    }
    cout << dp[n - 1][n - 1] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}