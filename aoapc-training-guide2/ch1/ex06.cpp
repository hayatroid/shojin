#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

const ll L[6] = {0, 1, 2, 3, 0, 0};
const ll T[6] = {0, 0, 0, 0, 1, 3};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    while (cin >> n && n) {
        char view[6][n][n], pos[n][n][n];
        rep(i, n) {
            vector<string> R(6);
            for (auto& r : R) cin >> r;
            rep(k, 6) rep(j, n) view[k][i][j] = R[k][j];
        }
        rep(i, n) rep(j, n) rep(k, n) pos[i][j][k] = '#';

        rep(k, 6) rep(i, n) rep(j, n) if (view[k][i][j] == '.') {
            rep(d, n) {
                ll x = i, y = j, z = d;
                rep(_, L[k]) swap(y, z), z = n - 1 - z;
                rep(_, T[k]) swap(x, z), z = n - 1 - z;
                pos[x][y][z] = '.';
            }
        }

        while (true) {
            bool done = true;
            rep(k, 6) rep(i, n) rep(j, n) if (view[k][i][j] != '.') {
                rep(d, n) {
                    ll x = i, y = j, z = d;
                    rep(_, L[k]) swap(y, z), z = n - 1 - z;
                    rep(_, T[k]) swap(x, z), z = n - 1 - z;
                    if (pos[x][y][z] == '.') continue;
                    if (pos[x][y][z] == '#') pos[x][y][z] = view[k][i][j];
                    if (pos[x][y][z] == view[k][i][j]) break;
                    pos[x][y][z] = '.';
                    done = false;
                }
            }
            if (done) break;
        }

        ll ans = 0;
        rep(i, n) rep(j, n) rep(k, n) if (pos[i][j][k] != '.') ans++;
        cout << "Maximum weight: " << ans << " gram(s)" << '\n';
    }
}
