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

int mex(set<int> &s) {
    int cur = 0;
    for (int x : s) {
        if (x != cur) return cur;
        cur++;
    }
    return cur;
}

void solve() {
    // G(x) = mex(G(y1) ^ G(y2))
    // where y1, y2 are all possible splits of x
    // If n = 2000, G(n) is never 0.
    int t; cin >> t;
    vector<int> q(t);
    int ma = 2000;
    vector<int> dp(ma + 1, 0);
    for (int i = 3; i <= ma; i++) {
        set<int> s;
        for (int j = 1; 2 * j < i; j++) {
            s.insert(dp[j] ^ dp[i-j]);
        }
        dp[i] = mex(s);
    }
    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        if (n > ma) cout << "first\n";
        else if (dp[n] == 0) cout << "second\n";
        else cout << "first\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}