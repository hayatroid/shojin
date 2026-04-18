#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    while (cin >> n >> m && n && m) {
        vector<ll> A(n), B(m);
        for (auto& a : A) cin >> a;
        for (auto& b : B) cin >> b;

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        ll ans = 0, cur = 0;
        for (ll b : B) {
            if (b >= A[cur]) {
                ans += b;
                if (++cur == n) break;
            }
        }
        if (cur == n) {
            cout << ans << '\n';
        } else {
            cout << "Loowater is doomed!\n";
        }
    }
}
