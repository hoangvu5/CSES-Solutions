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
    int n; ll x;
    cin >> n >> x;
    vector<pair<ll, int>> arr(n);
    for (int i = 0; i < n; i++) {
        ll cur; cin >> cur;
        arr[i] = {cur, i + 1};
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            ll cur = arr[i].first + arr[l].first + arr[r].first;
            if (cur > x) r--;
            else if (cur < x) l++;
            else {
                cout << arr[i].second << ' ' << arr[l].second << ' ' << arr[r].second << '\n';
                return;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}