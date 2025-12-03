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
    ll sum = 0; int prv, cur;
    cin >> prv;
    for (int i = 1; i < n; i++) {
        cin >> cur;
        sum += max(0, prv - cur);
        prv = max(prv, cur);
    }
    cout << sum << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}