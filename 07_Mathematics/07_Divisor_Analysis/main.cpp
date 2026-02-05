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

const int M = 1e9 + 7;

ll power(ll a, ll b) {
    ll ans = 1, cur = a;
    while (b) {
        if (b & 1) ans = ans * cur % M;
        cur = cur * cur % M;
        b /= 2;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    ll x, k;
    int C = 1, C2 = 1, S = 1, P = 1;
    for (int i = 1; i <= n; i++) {
        cin >> x >> k;
        C = C * (k + 1) % M;
        C2 = C2 * (k + 1) % (M - 1);
        S = S * (power(x, k + 1) - 1) % M * power(x - 1, M - 2) % M;
        P = power(P, k + 1) * power(power(x, k * (k + 1) / 2), C2) % M;
    }
    cout << C << ' ' << S << ' ' << P << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}