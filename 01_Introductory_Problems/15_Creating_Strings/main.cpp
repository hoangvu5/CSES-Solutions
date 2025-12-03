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
    string s; cin >> s;
    sort(s.begin(), s.end());
    vector<string> a;
    do a.push_back(s);
    while (next_permutation(s.begin(), s.end()));
    cout << a.size() << '\n';
    for (auto &x : a) cout << x << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}