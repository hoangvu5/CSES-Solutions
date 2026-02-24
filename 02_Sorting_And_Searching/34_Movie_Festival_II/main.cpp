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
    vector<array<int, 2>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    sort(arr.begin(), arr.end(), [&](const auto& a, const auto& b) {
        if (a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    });
    multiset<int> se;
    for (int i = 0; i < k; i++) {
        se.insert(0);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto &[st, en] = arr[i];
        // Find max smaller than or equal to st
        auto it = se.upper_bound(st);
        if (it != se.begin()) {
            se.erase(--it);
            se.insert(en);
            ans++;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}