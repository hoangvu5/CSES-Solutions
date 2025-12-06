#pragma GCC optimize("O3,unroll-loops")
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

const int N = 1e7 + 1;
int pref[N], suff[N], arr[N];

void solve() {
    int n, k; cin >> n >> k;
    int x, a, b, c; cin >> x >> a >> b >> c;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        arr[i] = x;
        x = (1ll * a * x + b) % c;
    }
    for (int i = 0; i < n; i++) {
        pref[i] = (i % k == 0) ? arr[i] : (pref[i - 1] | arr[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = (i % k == k - 1) ? arr[i] : (suff[i + 1] | arr[i]);
    }
    for (int i = 0; i <= n - k; i++) {
        int l = i, r = i + k - 1;
        int val = pref[r] | suff[l];
        ans ^= val;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}