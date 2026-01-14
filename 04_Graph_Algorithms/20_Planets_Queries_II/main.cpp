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
    vector<int> nxt(n);
    vector<vector<int>> prv(n);
    for (int i = 0; i < n; i++) {
        cin >> nxt[i];
        nxt[i]--;
        prv[nxt[i]].push_back(i);
    }

    // -2: Haven't processed this planet yet
    // -1: This is part of tree
    // >= 0: ID of cycle the planet belongs to
    vector<int> cycle_id(n, -2);
    // From cycle_idx and planet_idx, get planet's index in cycle
    vector<unordered_map<int, int>> cycles;
    for (int i = 0; i < n; i++) {
        if (cycle_id[i] != -2) continue;
        vector<int> path{i};
        int at = i;
        while (cycle_id[nxt[at]] == -2) {
            at = nxt[at];
            cycle_id[at] = -3;
            path.push_back(at);
        }

        unordered_map<int, int> cycle;
        bool in_cycle = false;
        for (int j : path) {
            in_cycle = in_cycle || j == nxt[at];
            if (in_cycle) { cycle[j] = cycle.size(); }
            cycle_id[j] = in_cycle ? cycles.size() : -1;
        }
        cycles.push_back(cycle);
    }

    // Calculate distance from each planet to its cycle with BFS
    vector<int> cyc_dist(n, 0);
    for (int i = 0; i < n; i++) {
        if (cycle_id[nxt[i]] == -1 || cycle_id[i] != -1) continue;
        cyc_dist[i] = 1;
        vector<int> stack(prv[i]);
        while (!stack.empty()) {
            int cur = stack.back();
            stack.pop_back();
            cyc_dist[cur] = cyc_dist[nxt[cur]] + 1;
            stack.insert(stack.end(), prv[cur].begin(), prv[cur].end());
        }
    }

    // Binary jumping
    int d = ceil(log2(n));
    vector<vector<int>> jmp(d + 1, nxt);
    for (int i = 1; i <= d; i++) {
        for (int j = 0; j < n; j++) {
            jmp[i][j] = jmp[i-1][jmp[i-1][j]];
        }
    }

    auto treeJmp = [&](int pos, int dist) {
        for (int i = d; i >= 0; i--) {
            if ((dist & (1 << i)) != 0)
                pos = jmp[i][pos];
        }
        return pos;
    };

    while (q--) {
        int u, v; cin >> u >> v;
        u--; v--;
        if (cycle_id[jmp[d][u]] != cycle_id[jmp[d][v]]) {
            cout << -1 << '\n';
            continue;
        }
        if (cycle_id[u] != -1 || cycle_id[v] != -1) {
            if (cycle_id[v] == -1 && cycle_id[u] != -1) {
                cout << -1 << '\n';
                continue;
            }
            int dist = cyc_dist[u];
            int u_cyc = treeJmp(u, cyc_dist[u]);
            unordered_map<int, int> &cyc = cycles[cycle_id[u_cyc]];
            int u_idx = cyc[u_cyc];
            int v_idx = cyc[v];
            int diff = u_idx <= v_idx ? v_idx - u_idx : cyc.size() - (u_idx - v_idx);
            cout << dist + diff << '\n';
            continue;
        } else {
            if (cyc_dist[v] > cyc_dist[u]) {
                cout << -1 << '\n';
                continue;
            }
        }
        int diff = cyc_dist[u] - cyc_dist[v];
        cout << (treeJmp(u, diff) == v ? diff : -1) << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}