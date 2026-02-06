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

const int m = 1e6 + 1;
int sieve[m], dp[m];
vector<int> primes;
ll ans = 0;

void solve() {
    for (int i = 2; i < m; i++) {
        if (!sieve[i]) {
            sieve[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > sieve[i] || i * p >= m) break;
            sieve[i * p] = p;
        }
    }

    int n, x; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;

        vector<int> pf;
        int tmp = x;
        while (tmp > 1) {
            int div = sieve[tmp];
            pf.push_back(div);
            while (tmp > 1 && tmp % div == 0) tmp /= div;
        }

        int k = pf.size();
        for (int mask = 0; mask < (1 << k); mask++) {
            int mu = 1;
            for (int i = 0; i < k; i++) {
                if (mask & (1 << i)) mu *= pf[i];
            }
            int bit = __builtin_popcount(mask);
            ans += ((bit & 1) ? -dp[mu] : dp[mu]);
            dp[mu]++;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}