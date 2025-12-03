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

const int m = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> arr(6, 0);
    arr[0] = 1;
    for (int i = 1; i <= n; i++) {
        int cur = 0;
        for (int j = 1; j <= 6; j++) {
            cur = (cur + arr[(i - j + 6) % 6]) % m;
        }
        arr[i % 6] = cur;
    }
    cout << arr[n % 6] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}