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
    if (n % 4 == 1 || n % 4 == 2) {
        cout << 0 << '\n';
        return;
    }
    // Count ways to get a sum x containing i in the set
    int x = n * (n + 1) / 4;
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - i >= 0) dp[i][j] = (dp[i][j] + dp[i-1][j-i]) % m;
        }
    }
    cout << dp[n][x] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}