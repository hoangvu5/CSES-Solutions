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
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vector<string> mat(n);
    for (int i = 0; i < n; i++) cin >> mat[i];
    string ans = "";
    vector<pair<int, int>> cur, nxt;
    cur.push_back({0, 0});
    ans += mat[0][0];
    for (int i = 1; i < 2 * n - 1; i++) {
        char cand = 'Z';
        nxt.clear();
        for (auto &[x, y] : cur) {
            if (x + 1 < n) cand = min(cand, mat[x + 1][y]);
            if (y + 1 < n) cand = min(cand, mat[x][y + 1]);
        }
        for (auto &[x, y] : cur) {
            if (x + 1 < n && mat[x + 1][y] == cand && !vis[x + 1][y]) {
                vis[x + 1][y] = true;
                nxt.push_back({x + 1, y});
            }
            if (y + 1 < n && mat[x][y + 1] == cand && !vis[x][y + 1]) {
                vis[x][y + 1] = true;
                nxt.push_back({x, y + 1});
            }
        }
        ans += cand;
        cur.swap(nxt);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}