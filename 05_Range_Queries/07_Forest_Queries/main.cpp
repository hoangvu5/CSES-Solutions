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
    int n, q; cin >> n >> q;
    vector<string> forest(n);
    vector<vector<int>> pref(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
        cin >> forest[i];
        for (int j = 0; j < n; j++) {
            pref[i+1][j+1] = pref[i+1][j] + pref[i][j+1] - pref[i][j] + (forest[i][j] == '*');
        }
    }
    while (q--) {
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        cout << pref[y2][x2] - pref[y2][x1-1] - pref[y1-1][x2] + pref[y1-1][x1-1] << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}