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

ll dp[20][2][11];
ll a, b, A, B;
string sa, sb;

ll digitDP(int i, bool tight, int last, const string& s) {
    if (i == s.size()) return dp[i][tight][last] = 1;
    if (!tight && dp[i][tight][last] != -1) return dp[i][tight][last];
    ll ans = 0;
    int digit = tight ? s[i] - '0' : 9;
    for (int d = 0; d <= digit; d++) {
        if (last != 10 && d == last) continue;
        bool new_tight = (d == digit) ? tight : 0;
        int new_last = (d == 0 && last == 10) ? 10 : d; 
        ans += digitDP(i + 1, new_tight, new_last, s);
    }
    if (!tight) dp[i][tight][last] = ans;
    return ans;
}

void solve() {
    cin >> a >> b;
    sa = to_string(a - 1); sb = to_string(b);
    while (sa.size() < sb.size()) sa = "0" + sa;
    memset(dp, -1, sizeof(dp));

    A = a ? digitDP(0, 1, 10, sa) : 0;
    B = b ? digitDP(0, 1, 10, sb) : 1;
    cout << B - A << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}