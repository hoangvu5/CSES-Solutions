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

bool isTriangular(ll n) {
    ll s = sqrt(8 * n + 1);
    return (s * s == 8 * n + 1 && (s - 1) % 2 == 0);
}

void solve() {
    // Triangle number: k(k + 1) / 2 = n
    // k^2 + k - 2n = 0
    // (sqrt(8n+1) - 1) / 2 is an integer

    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        ll n; cin >> n;
        if (isTriangular(n)) {
            cout << 1 << '\n';
        } else {
            bool check = false;
            for (ll i = 1; i * (i + 1) / 2 <= n; i++) {
                if (isTriangular(n - i * (i + 1) / 2)) {
                    cout << 2 << '\n';
                    check = true;
                    break;
                }
            }
            if (!check) cout << 3 << '\n';
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}