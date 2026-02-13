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

int expo(int a, int b) {
    int ans = 1, cur = a;
    while (b) {
        if (b & 1) ans = 1ll * ans * cur % M;
        cur = 1ll * cur * cur % M;
        b /= 2;
    }
    return ans;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> A(n, vi(m + 1)); // size (n, m + 1)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            cin >> A[i][j];
        }
    }

    vi where(m, -1);
    for (int col = 0, row = 0; col < m && row < n; col++) {
        int sel = row;
        // Find row with max abs of A[i][col]
        for (int i = row; i < n; i++) {
            // But meaningless under mod M
            // if (A[i][col] > A[sel][col]) sel = i;
            if (A[i][col] != 0) {
                sel = i;
                break;
            }
        }
        // If all is = 0, then skip the column
        if (A[sel][col] == 0) continue;
        // Swap remaining coeff. of current row and chosen row
        for (int i = col; i <= m; i++) {
            swap(A[sel][i], A[row][i]);
        }
        where[col] = row;

        for (int i = 0; i < n; i++) {
            if (i != row) {
                int c = 1ll * A[i][col] * expo(A[row][col], M - 2) % M;
                for (int j = col; j <= m; j++) {
                    A[i][j] = (A[i][j] - 1ll * c * A[row][j] % M + M) % M;
                }
            }
        }
        row++;
    }

    vi ans(m, 0);
    for (int i = 0; i < m; i++) {
        if (where[i] != -1) {
            ans[i] = 1ll * A[where[i]][m] * expo(A[where[i]][i], M - 2) % M;
        }
    }
    // Simply check for no solution case
    int possible = 1;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum = (sum + 1ll * ans[j] * A[i][j] % M) % M;
        }
        if ((sum - A[i][m]) % M != 0) {
            possible = 0;
            break;
        }
    }
    if (possible == 0) {
        cout << -1 << '\n';
        return;
    }
    // Independent variable
    for (int i = 0; i < m; i++) {
        if (where[i] == -1) {
            possible = 2;
            cout << 0 << ' ';
        } else {
            cout << ans[i] << ' ';
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}