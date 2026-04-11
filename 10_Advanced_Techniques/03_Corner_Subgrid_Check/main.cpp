#pragma GCC optimize("O3,unroll-loops")
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

int n, k;

bool check(const vector<vector<int>>& arr) {
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    for (auto &a : arr) {
        for (int x = 0; x < a.size(); x++) {
            for (int y = x + 1; y < a.size(); y++) {
                if (vis[a[x]][a[y]]) return true;
                vis[a[x]][a[y]] = true;
            }
        }
    }
    return false;
}

void solve() {
    cin >> n >> k;
    vector<vector<vector<int>>> arr(k, vector<vector<int>>(n));
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            int l = s[j] - 'A';
            if (l < k) arr[l][i].emplace_back(j);
        }
    }
    for (int i = 0; i < k; i++) {
        if (check(arr[i])) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}