#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout<<#x<<" = "<<x<<'\n'
#define dbgv(x) for(int i=0;i<x.size();i++)cout<<x[i]<<' ';cout<<'\n'
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128_t i128;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int M = 1e9 + 7;
const ll L = (1ll << 61) - 1;
const ll K = 31;

ll mul(ll a, ll b) {
    return (ll)((i128)a * b % L);
}

void solve() {
    string s; cin >> s;
    int n = s.size();
    int k; cin >> k;
    string t;
    unordered_map<int, unordered_set<ll>> moves;
    for (int i = 0; i < k; i++) {
        cin >> t;
        ll h = 0;
        for (int j = 0; j < t.size(); j++) {
            h = (mul(h, K) + (t[j] - 'a' + 1)) % L;
        }
        moves[t.size()].insert(h);
    }
    vector<ll> pw(n + 1, 0);
    vector<ll> hash(n + 1, 0);
    pw[0] = 1;
    for (int i = 0; i < n; i++) {
        hash[i + 1] = (mul(hash[i], K) + (s[i] - 'a' + 1)) % L;
        pw[i + 1] = mul(pw[i], K);
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            ll h = (hash[i] - mul(hash[j], pw[i - j]) + L) % L;
            if (moves[i - j].find(h) != moves[i - j].end()) {
                dp[i] = (1ll * dp[i] + dp[j]) % M;
            }
        }
    }
    cout << dp[n] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}