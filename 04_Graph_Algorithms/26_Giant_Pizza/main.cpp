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

int k;
vector<vector<int>> adj, inv;
vector<int> topo, idx, ans;
vector<bool> vis;

void dfsa(int v) {
    vis[v] = true;
    for (auto &u : adj[v]) {
        if (!vis[u]) dfsa(u);
    }
    topo.push_back(v);
}

void dfsi(int v) {
    idx[v] = k;
    for (auto &u : inv[v]) {
        if (idx[u] == -1) dfsi(u);
    }
}

void solve() {
    // SAT (Boolean satisfiability Problem): NP-complete
    // 2-SAT
    // - TC: O(n + m) where n: number of variables, m: number of clauses
    // - Literals: Variables (x) or negation of variables (!x)
    // - Conjunctive normal form: Conjunction of multiple clauses, each is disjunction of literals
    // - Convert the problem to implicative normal form: a or b into !a -> b and !b -> a
    // Implication graph
    // - For each variable x, has two vertices v_x and v_!x
    // Condition for solution: 
    // - If a -> !a, and !a -> a, then no solution
    // - a and !a must be in different SCC
    int n, m; cin >> m >> n;
    adj.resize(2 * n);
    inv.resize(2 * n);
    for (int i = 0; i < m; i++) {
        string sa, sb; int a, b, na, nb; bool ba, bb;
        cin >> sa >> a >> sb >> b;
        a--; b--;
        // Boolean is for whether to be negated
        ba = (sa == "-"), bb = (sb == "-");
        a = 2 * a ^ ba;
        b = 2 * b ^ bb;
        na = a ^ 1;
        nb = b ^ 1;
        adj[na].push_back(b);
        adj[nb].push_back(a);
        inv[b].push_back(na);
        inv[a].push_back(nb);
    }

    vis.assign(2 * n, false);
    topo.clear();
    for (int i = 0; i < 2 * n; i++) {
        if (!vis[i]) dfsa(i);
    }
    idx.assign(2 * n, -1);
    reverse(topo.begin(), topo.end());
    k = 0;
    for (auto &v : topo) {
        if (idx[v] == -1) k++, dfsi(v);
    }
    ans.resize(n);
    for (int i = 0; i < 2 * n; i += 2) {
        if (idx[i] == idx[i + 1]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        ans[i / 2] = idx[i] > idx[i + 1];
    }
    for (int i = 0; i < n; i++) cout << (ans[i] ? "+ " : "- ");
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}