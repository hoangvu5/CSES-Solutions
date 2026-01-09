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
    int n, m; cin >> n >> m;
    vector<vector<int>> dp(m + 1, vector<int>((1 << n), 0));
    vector<vector<int>> nxt(1 << n);
    for (int mask = 0; mask < (1 << n); mask++) {
        stack<pair<int, int>> st;
        st.push({0, 0});
        while (!st.empty()) {
            auto [row, sub] = st.top();
            st.pop();
            while (row < n && (mask & (1 << row))) row++;
            if (row == n) {
                nxt[mask].push_back(sub);
                continue;
            }
            if (row + 1 < n && !(mask & (1 << (row + 1))))
                st.push({row + 2, sub});
            st.push({row + 1, sub | (1 << row)});
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[i][mask] == 0) continue;
            for (int sub : nxt[mask]) {
                dp[i + 1][sub] = (dp[i + 1][sub] + dp[i][mask]) % MOD;
            }
        }
    }
    cout << dp[m][0] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}