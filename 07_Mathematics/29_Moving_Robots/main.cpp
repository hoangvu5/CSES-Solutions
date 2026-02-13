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

double cur[64][8][8];
double nxt[64][8][8];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void solve() {
    // P(empty) = product of (1 - P(robot i at this position))
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            cur[x * 8 + y][x][y] = 1;
        }
    }
    int k; cin >> k;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < 64; j++) {
            for (int x = 0; x < 8; x++) {
                for (int y = 0; y < 8; y++) {
                    double valid = 0;
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dir[k][0], ny = y + dir[k][1];
                        if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) valid++;
                    }
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dir[k][0], ny = y + dir[k][1];
                        if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
                            nxt[j][nx][ny] += cur[j][x][y] / valid;
                    }
                }
            }
        }
        memcpy(cur, nxt, sizeof(cur));
        memset(nxt, 0, sizeof(nxt));
    }

    double ev = 0;
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            double prob = 1;
            for (int i = 0; i < 64; i++) {
                prob *= 1 - cur[i][x][y];
            }
            ev += prob;
        }
    }
    cout << fixed << setprecision(6) << ev << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}