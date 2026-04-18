#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    while (cin >> n && n) {
        vector<pair<ll, ll>> P(n);
        for (auto& p : P) cin >> p.second >> p.first;  // (J, B)

        sort(P.rbegin(), P.rend());
        ll ans = 0, acc = 0;
        for (auto p : P) {
            acc += p.second;
            ans = max(ans, acc + p.first);
        }
        static ll Case = 0;
        cout << "Case " << ++Case << ": " << ans << '\n';
    }
}
