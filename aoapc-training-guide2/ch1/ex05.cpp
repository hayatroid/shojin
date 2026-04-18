#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Ant {
    ll pos;
    string dir;
    ll idx;
};

void solve() {
    ll l, t, n;
    cin >> l >> t >> n;
    vector<Ant> A(n);
    for (ll i = 0; i < n; ++i) {
        cin >> A[i].pos >> A[i].dir;
        A[i].idx = i;
    }
    sort(A.begin(), A.end(), [&](Ant& x, Ant& y) { return x.pos < y.pos; });

    vector<Ant> B(n);
    for (ll i = 0; i < n; ++i) {
        ll sgn = (A[i].dir == "R") ? 1 : -1;
        B[i].pos = A[i].pos + sgn * t;
        B[i].dir = A[i].dir;
    }
    sort(B.begin(), B.end(), [&](Ant& x, Ant& y) { return x.pos < y.pos; });
    for (ll i = 0; i < n; ++i) B[i].idx = A[i].idx;

    for (ll i = 0; i + 1 < n; ++i) {
        if (B[i].pos == B[i + 1].pos) {
            B[i].dir = B[i + 1].dir = "Turning";
        }
    }
    sort(B.begin(), B.end(), [&](Ant& x, Ant& y) { return x.idx < y.idx; });

    static ll Case = 0;
    cout << "Case #" << ++Case << ":\n";
    for (auto& b : B) {
        if (0 <= b.pos && b.pos <= l) {
            cout << b.pos << ' ' << b.dir << '\n';
        } else {
            cout << "Fell off\n";
        }
    }

    // avoid presentation error!
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll T;
    cin >> T;
    while (T--) solve();
}
