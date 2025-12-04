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
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << '\n';
    int x = n, y = m;
    vector<int> seq;
    while (x > 0 && y > 0) {
        if (a[x - 1] == b[y - 1]) {
            seq.push_back(a[x - 1]);
            x--; y--;
        } else {
            if (dp[x - 1][y] > dp[x][y - 1]) x--;
            else y--;
        }
    }
    reverse(seq.begin(), seq.end());
    for (auto &x : seq) cout << x << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}