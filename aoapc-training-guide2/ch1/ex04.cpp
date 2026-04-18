#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    while (cin >> n >> m) {
        double ans = 0;
        for (ll i = 0; i < n; ++i) {
            double cur = (double)i / n * (n + m);
            ans += abs(cur - round(cur));
        }
        cout << fixed << setprecision(4) << ans / (n + m) * 10000 << '\n';
    }
}
