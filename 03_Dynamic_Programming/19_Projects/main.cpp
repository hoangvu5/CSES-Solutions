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
    int n; cin >> n;
    vector<vector<int>> proj(n, vector<int>(3, 0));
    vector<ll> dp(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> proj[i][0] >> proj[i][1] >> proj[i][2];
    }
    sort(proj.begin(), proj.end(), [&](auto &a, auto &b) {
        if (a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    });
    for (int i = 0; i < n; i++) {
        int lo = -1, hi = i - 1;
        while (lo < hi) {
            int mi = lo + (hi - lo + 1) / 2;
            if (mi == -1 || proj[mi][1] < proj[i][0]) lo = mi;
            else hi = mi - 1;
        }
        dp[i] = max((i ? dp[i - 1] : 0), (lo == -1 ? 0 : dp[lo]) + proj[i][2]);
    }
    cout << dp[n - 1] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}