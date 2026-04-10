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
    int n, x, v; cin >> n >> x;
    string s;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> s; v = 0;
        for (const char& c : s) v = v * 2 + (c - '0');
        arr[i] = v;
    }
    int ans = x;
    for (int i = 0; i < n && ans >= 1; i++) {
        for (int j = i + 1; j < n && ans >= 1; j++) {
            ans = min(ans, __builtin_popcount(arr[i] ^ arr[j]));
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}