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
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> par(n + 1, -1);
    queue<int> qu;
    qu.push(1); par[1] = 0;
    while (!qu.empty()) {
        int si = qu.size();
        for (int i = 0; i < si; i++) {
            int cur = qu.front(); qu.pop();
            if (cur == n) {
                vector<int> ans;
                int x = n;
                while (x != 0) {
                    ans.push_back(x);
                    x = par[x];
                }
                reverse(ans.begin(), ans.end());
                cout << ans.size() << '\n';
                for (auto &num : ans) cout << num << ' ';
                return;
            }
            for (auto &chi : adj[cur]) {
                if (par[chi] != -1) continue;
                par[chi] = cur;
                qu.push(chi);
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}