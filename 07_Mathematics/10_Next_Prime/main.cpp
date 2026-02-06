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
int sieve[m];
vector<int> primes;

bool is_prime(ll n) {
    for (int i = 0; i < primes.size() && 1ll * primes[i] * primes[i] <= n; i++) {
        if (n % primes[i] == 0) return false;
    }
    return true;
}

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

    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        n++;
        while (!is_prime(n)) n++;
        cout << n << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}