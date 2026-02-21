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
    int n, mx; cin >> n;
    vector<array<int, 3>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
        arr[i][2] = i;
    }
    
    sort(arr.begin(), arr.end(), [&](auto& a, auto& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });
    mx = INT_MAX;
    vector<bool> a(n), b(n);
    // Check if it contains others
    for (int i = n - 1; i >= 0; i--) {
        auto &[st, en, idx] = arr[i];
        a[idx] = (mx <= en);
        mx = min(mx, en);
    }
    // Check if other contains it
    mx = 0;
    for (int i = 0; i < n; i++) {
        auto &[st, en, idx] = arr[i];
        b[idx] = (en <= mx);
        mx = max(mx, en);
    }

    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) cout << b[i] << ' ';
    cout << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}