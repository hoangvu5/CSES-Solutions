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

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
string arr = "DURL";

void solve() {
    int n, m; cin >> n >> m;
    vector<string> mat(n);
    vector<pii> mon;
    int ax, ay;
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'A') {
                ax = i, ay = j;
            } else if (mat[i][j] == 'M') {
                mon.emplace_back(i, j);
            }
        }
    }

    queue<pair<int, pii>> qu;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    int k = mon.size();
    for (int i = 0; i < k; i++) {
        qu.push({0, mon[i]});
        dist[mon[i].first][mon[i].second] = 0;
    }

    while (!qu.empty()) {
        int d = qu.front().first;
        int x = qu.front().second.first;
        int y = qu.front().second.second;
        qu.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny] != '#' && d + 1 < dist[nx][ny]) {
                dist[nx][ny] = d + 1;
                qu.push({dist[nx][ny], {nx, ny}});
            }
        }
    }

    vector<vector<char>> par(n, vector<char>(m, ' '));
    qu.push({0, {ax, ay}}); dist[ax][ay] = 0;
    bool check = false;
    int dx, dy;
    while (!qu.empty()) {
        int d = qu.front().first;
        int x = qu.front().second.first;
        int y = qu.front().second.second;
        qu.pop();
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            check = true;
            dx = x, dy = y;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny] != '#' && d + 1 < dist[nx][ny]) {
                dist[nx][ny] = d + 1;
                qu.push({dist[nx][ny], {nx, ny}});
                par[nx][ny] = arr[i];
            }
        }
    }

    if (!check) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    string ans = "";
    while (par[dx][dy] != ' ') {
        for (int i = 0; i < 4; i++) {
            if (par[dx][dy] == arr[i]) {
                ans += arr[i];
                dx -= dir[i][0];
                dy -= dir[i][1];
            }
        }
    }
    cout << ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}