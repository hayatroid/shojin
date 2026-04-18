#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    while (cin >> n) {
        vector<ll> A(n);
        for (auto& a : A) cin >> a;

        ll m = 0;
        for (ll a : A) m += a;
        m /= n;

        vector<ll> C;
        ll acc = 0;
        for (ll a : A) C.push_back(acc), acc += a - m;

        ll ans = 0;
        sort(C.begin(), C.end());
        for (ll c : C) ans += abs(c - C[n / 2]);
        cout << ans << '\n';
    }
}
