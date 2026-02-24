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
    unordered_map<int, int> ma;
    ma[0] = 1;
    int pref = 0; ll ans = 0;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        pref = (pref + v) % n;
        if (pref < 0) pref += n;
        ans += ma[pref];
        ma[pref]++;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}