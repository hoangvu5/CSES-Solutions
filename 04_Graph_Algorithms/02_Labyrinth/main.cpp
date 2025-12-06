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
string arr = "UDRL";

struct Node {
    int x, y;
    int g, h;
    int f() const { return g + h; }
};

struct Compare {
    bool operator()(const Node &a, const Node &b) {
        return a.f() > b.f();
    }
};

int H(int x, int y, int gx, int gy) {
    // Heuristic: Manhattan distance
    return abs(x - gx) + abs(y - gy);
}

vector<pii> buildPath(vector<vector<pii>> &parent, pii B, pii A) {
    vector<pii> path;
    auto [x, y] = B;
    while (x != A.first || y != A.second) {
        path.push_back({x, y});
        tie(x, y) = parent[x][y];
    }
    path.push_back(A);
    reverse(path.begin(), path.end());
    return path;
}

string buildDirection(vector<vector<pii>> &parent, pii B, pii A) {
    string direction = "";
    auto [x, y] = B;
    while (x != A.first || y != A.second) {
        auto [px, py] = parent[x][y];
        for (int i = 0; i < 4; i++) {
            if (x - px == dir[i][0] && y - py == dir[i][1]) {
                direction.push_back(arr[i]);
                break;
            }
        }
        tie(x, y) = parent[x][y];
    }
    
    reverse(direction.begin(), direction.end());
    return direction;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<string> mat(n);
    pii start, goal;
    
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'A') start.first = i, start.second = j;
            if (mat[i][j] == 'B') goal.first = i, goal.second = j;
        }
    }
    
    auto [sx, sy] = start;
    auto [gx, gy] = goal;
    priority_queue<Node, vector<Node>, Compare> pq;
    vector<vector<int>> G(n, vector<int>(m, INT_MAX));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<pii>> par(n, vector<pii>(m, {-1,-1}));

    G[sx][sy] = 0;
    pq.push({sx, sy, 0, H(sx, sy, gx, gy)});

    string ans;
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int x = cur.x, y = cur.y;
        if (vis[x][y]) continue;
        vis[x][y] = true;
        if (x == gx && y == gy) {
            ans = buildDirection(par, goal, start);
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || mat[nx][ny] == '#') continue;
            int ng = G[x][y] + 1;
            if (ng < G[nx][ny]) {
                G[nx][ny] = ng;
                par[nx][ny] = {x, y};
                int nh = H(nx, ny, gx, gy);
                pq.push({nx, ny, ng, nh});
            }
        }
    }

    if (ans.empty()) {
        cout << "NO\n";
    } else {
        cout << "YES\n" << ans.size() << '\n' << ans << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}