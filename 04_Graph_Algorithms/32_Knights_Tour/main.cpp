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

int dx[8] = {1, 2, 1, -2, -2, -1, 2, -1};
int dy[8] = {2, 1, -2, 1, -1, -2, -1, 2};
const int N = 8;
int vis[N][N];

bool dfs(int x, int y, int idx) {
    vis[x][y] = idx;
    if (idx == 64) return true;
    set<pair<int, int>> se;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && vis[nx][ny] == 0) {
            int c = 0;
            for (int j = 0; j < 8; j++) {
                int mx = nx + dx[j];
                int my = ny + dy[j];
                c += (mx >= 0 && mx < N && my >= 0 && my < N && vis[mx][my] == 0);
            }
            se.insert({c, i});
        }
    }
    for (auto &[c, i] : se) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (dfs(nx, ny, idx + 1)) return true;
    }
    vis[x][y] = 0;
    return false;
}

void solve() {
    int sx, sy; cin >> sx >> sy;
    sx--; sy--;
    dfs(sy, sx, 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << vis[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}