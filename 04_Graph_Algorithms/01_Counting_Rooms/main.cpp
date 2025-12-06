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

int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void solve() {
    int n, m; cin >> n >> m;
    vector<string> mat(n);
    function<void(int, int)> dfs = [&](const int &x, const int &y) {
        mat[x][y] = '#';
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == '.') {
                dfs(nx, ny);
            }
        }
    };
    int ans = 0;
    for (int i = 0; i < n; i++) cin >> mat[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '#') continue;
            dfs(i, j); ans++;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}