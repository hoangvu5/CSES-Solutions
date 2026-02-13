#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout<<#x<<" = "<<x<<'\n'
#define dbgv(x) for(int i=0;i<x.size();i++)cout<<x[i]<<' ';cout<<'\n'
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

vector<vi> mat_mul(vector<vi> &a, vector<vi> &b) {
    // a: [A, B]
    // b: [B, C]
    // c: [A, C]
    int A = a.size(), B = b.size(), C = b[0].size();
    vector<vi> c(A, vi(C, LLONG_MAX));
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < C; j++) {
            for (int k = 0; k < B; k++) {
                if (a[i][k] != LLONG_MAX && b[k][j] != LLONG_MAX)
                    c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    return c;
}

vector<vi> mat_expo(vector<vi> &a, ll b) {
    vector<vi> ans(a.size(), vi(a[0].size(), LLONG_MAX));
    for (int i = 0; i < a.size(); i++) ans[i][i] = 0;
    vector<vi> cur = a;
    while (b) {
        if (b & 1) ans = mat_mul(ans, cur);
        cur = mat_mul(cur, cur);
        b /= 2;
    }
    return ans;
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    // k = 1, answer is adjacency matrix
    // k > 1, answer is min(dist[i][j] + dist[j][k])
    vector<vi> mat(n, vi(n, LLONG_MAX));
    for (int i = 0; i < m; i++) {
        int a, b; ll c; cin >> a >> b >> c;
        a--; b--;
        mat[a][b] = min(mat[a][b], c);
    }

    mat = mat_expo(mat, k);
    cout << ((mat[0][n-1] == LLONG_MAX) ? -1 : mat[0][n-1]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}