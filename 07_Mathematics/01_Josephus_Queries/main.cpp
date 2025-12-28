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

map<pii, int> f;

int josephus(int n, int k) {
    if (f[{n, k}]) return f[{n, k}];
    if (n == 1) return f[{n, k}] = 1;
    int half = n / 2;
    if (k <= half) return f[{n, k}] = 2 * k;

    int res = josephus(n - half, k - half);
    if (n % 2 == 1) {
        return f[{n, k}] = ((2 * res - 3) + (n + 1)) % (n + 1);
    } else {
        return f[{n, k}] = 2 * res - 1;
    }
}

void solve() {
    int q; cin >> q;
    while (q--) {
        int n, k; cin >> n >> k;
        cout << josephus(n, k) << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}