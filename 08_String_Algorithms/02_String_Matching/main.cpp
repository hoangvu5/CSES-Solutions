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
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    string S = t + "$" + s;
    vector<int> kmp(S.size(), 0);
    kmp[0] = 0;
    int ans = 0;
    for (int i = 1; i < S.size(); i++) {
        int j = kmp[i - 1];
        while (j > 0 && S[i] != S[j]) j = kmp[j - 1];
        if (S[i] == S[j]) j++;
        kmp[i] = j;
        if (i > m && kmp[i] == m) ans++;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}