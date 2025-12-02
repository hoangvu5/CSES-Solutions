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
    int n; cin >> n;
    pair<int, int> t[2 * n];
    for (int i = 0; i < 2 * n; i += 2) {
        int a, b; cin >> a >> b;
        t[i] = {a, 1};
        t[i + 1] = {b, -1};
    }
    sort(t, t + 2 * n);
    int ans = 0, sum = 0;
    for (int i = 0; i < 2 * n; i++) {
        sum += t[i].second;
        ans = max(ans, sum);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}