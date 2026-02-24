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
    int n, k; cin >> n >> k;
    // At most k distinct values
    vector<int> arr(n);
    map<int, int> ma;
    int prv = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ma[arr[i]]++;
        while (ma.size() > k) {
            if (--ma[arr[prv]] == 0) ma.erase(arr[prv]);
            prv++;
        }
        ans += i - prv + 1;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}