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
    vector<int> arr(n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        m = max(m, arr[i]);
    }
    vector<int> vis(m + 1, 0);
    for (int i = 0; i < n; i++) {
        vis[arr[i]]++;
    }
    for (int i = m; i >= 1; i--) {
        int cnt = 0;
        for (int j = i; j <= m; j += i) {
            cnt += vis[j];
        }
        if (cnt >= 2) {
            cout << i << '\n';
            return;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}