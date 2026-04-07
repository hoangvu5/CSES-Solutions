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

vector<vi> treeJump(vi& P){
    int on = 1, d = 1;
    while(on < sz(P)) on *= 2, d++;
    vector<vi> jmp(d, P);
    rep(i,1,d) rep(j,0,sz(P))
        jmp[i][j] = jmp[i-1][jmp[i-1][j]];
    return jmp;
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    stack<int> st;
    vector<int> nge(n + 1, n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        while (!st.empty() && arr[st.top()] < arr[i]) {
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    vector<vector<int>> tbl = treeJump(nge);
    int a, b;
    while (q--) {
        cin >> a >> b;
        a--; b--;
        int ans = 0;
        for (int i = tbl.size() - 1; i >= 0 && a <= b; i--) {
            int d = tbl[i][a];
            if (d <= b) {
                ans += (1 << i);
                a = d;
            }
        }
        cout << ans + 1 << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}