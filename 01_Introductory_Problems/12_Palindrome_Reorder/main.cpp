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
    int n = s.size();
    int ma[26] = { 0 };
    for (const char &c : s) ma[c - 'A']++;
    int odd = 0;
    for (auto &f : ma) odd += (f % 2 == 1);
    if ((n % 2 == 0 && odd > 0) || (n % 2 == 1 && odd > 1)) {
        cout << "NO SOLUTION\n";
        return;
    }
    int idx = 0;
    for (int i = 0; i < 26; i++) {
        int f = ma[i];
        char c = (char)(i + 'A');
        while (f > 1) {
            s[idx] = s[n - 1 - idx] = c;
            idx++; f -= 2;
        }
        if (f == 1) s[n / 2] = c;
    }
    cout << s << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}