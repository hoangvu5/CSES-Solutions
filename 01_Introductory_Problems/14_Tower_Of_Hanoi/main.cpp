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

vector<vector<int>> moves;

void recurse(int n, int src, int dst, int aux) {
    if (n == 1) {
        moves.push_back({src, dst});
        return;
    }
    recurse(n - 1, src, aux, dst);
    moves.push_back({src, dst});
    recurse(n - 1, aux, dst, src);
}

void solve() {
    int n; cin >> n;
    moves.clear();
    recurse(n, 1, 3, 2);
    cout << moves.size() << '\n';
    for (auto &m : moves) cout << m[0] << ' ' << m[1] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}