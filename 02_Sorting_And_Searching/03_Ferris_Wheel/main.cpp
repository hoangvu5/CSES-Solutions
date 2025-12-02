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

void solve() {
    int n, x; cin >> n >> x;
    int p[n];
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p, p + n);
    int l = 0, r = n - 1, ans = 0;
    while (l <= r) {
        if (p[l] + p[r] > x) ans++, r--;
        else l++, r--, ans++;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}