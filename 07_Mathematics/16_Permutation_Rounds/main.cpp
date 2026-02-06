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

int expo(int a, int b) {
    int ans = 1, cur = a;
    while (b) {
        if (b & 1) ans = 1ll * ans * cur % M;
        cur = 1ll * cur * cur % M;
        b /= 2;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> arr(n + 1);
    vector<bool> vis(n + 1, 0);
    map<int, int> max_expo;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int cur = i, si = 0;
        while (!vis[cur]) {
            vis[cur] = true;
            si++; cur = arr[cur];
        }
        for (int p = 2; 1 * p * p <= si; p++) {
            int cnt = 0;
            while (si % p == 0) {
                si /= p;
                cnt++;
            }
            max_expo[p] = max(max_expo[p], cnt);
        }
        if (si > 1) max_expo[si] = max(max_expo[si], 1);
    }
    int ans = 1;
    for (auto &[p, e] : max_expo) {
        ans = 1ll * ans * expo(p, e) % M;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}