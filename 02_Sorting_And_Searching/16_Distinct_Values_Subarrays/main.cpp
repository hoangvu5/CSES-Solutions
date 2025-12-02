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
    map<int, int> ma;
    int n; cin >> n;
    int last = -1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (ma.find(x) != ma.end()) last = max(last, ma[x]);
        ans += i - last;
        ma[x] = i;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}