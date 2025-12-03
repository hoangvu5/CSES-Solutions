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
    int n; cin >> n;
    if (n % 4 == 1 || n % 4 == 2) {
        cout << "NO\n";
    } else if (n % 4 == 3) {
        cout << "YES\n" << (n + 1) / 2 << "\n1 2 ";
        for (int i = 4; i < (n + 5) / 2; i += 2) cout << i << ' ' << n + 4 - i << ' ';
        cout << "\n" << n / 2 << "\n3 ";
        for (int i = 5; i < (n + 5) / 2; i += 2) cout << i << ' ' << n + 4 - i << ' ';
    } else {
        cout << "YES\n" << n / 2 << "\n";
        for (int i = 1; i <= n / 2; i += 2) cout << i << ' ' << n + 1 - i << ' ';
        cout << '\n' << n / 2 << '\n';
        for (int i = 2; i <= n / 2; i += 2) cout << i << ' ' << n + 1 - i << ' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}