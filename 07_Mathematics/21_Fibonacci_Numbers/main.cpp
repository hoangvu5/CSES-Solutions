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

const int M = 1e9 + 7;

vector<vi> mat_mul(vector<vi> &a, vector<vi> &b) {
    // a: [A, B]
    // b: [B, C]
    // c: [A, C]
    int A = a.size(), B = b.size(), C = b[0].size();
    vector<vi> c(A, vi(C, 0));
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < C; j++) {
            for (int k = 0; k < B; k++) {
                c[i][j] += 1ll * a[i][k] * b[k][j] % M;
                c[i][j] %= M;
            }
        }
    }
    return c;
}

vector<vi> mat_expo(vector<vi> &a, ll b) {
    vector<vi> ans(a.size(), vi(a[0].size(), 0));
    for (int i = 0; i < a.size(); i++) ans[i][i] = 1;
    vector<vi> cur = a;
    while (b) {
        if (b & 1) ans = mat_mul(ans, cur);
        cur = mat_mul(cur, cur);
        b /= 2;
    }
    return ans;
}

void solve() {
    // fn = fn-2 + fn-1
    // (fn, fn-1) = (fn-1, fn-2) * (11, 10)
    ll n; cin >> n;
    if (n == 0) cout << 0;
    else if (n == 1) cout << 1;
    else {
        vector<vi> mat = {{1, 1}, {1, 0}};
        cout << mat_expo(mat, n - 1)[0][0];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}