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

const int MAX_N = 1e6;
int max_div[MAX_N + 1];

// Use x = p1^a1 * p2^a2 * ... * pn^an
void solve() {
    for (int i = 2; i <= MAX_N; i++) {
        if (max_div[i] == 0) {
            for (int j = i; j <= MAX_N; j += i) {
                max_div[j] = i;
            }
        }
    }

    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        int res = 1;
        while (x != 1) {
            int prime = max_div[x];
            int cnt = 0;
            while (x % prime == 0) {
                cnt++;
                x /= prime;
            }
            res *= cnt + 1;
        }
        cout << res << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}