#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, c1, c2, v;
    cin >> n >> m >> c1 >> c2 >> v;

    vector<ll> stairs(c1), elev(c2);
    for (ll &x : stairs) cin >> x;
    for (ll &x : elev) cin >> x;

    int q;
    cin >> q;

    while (q--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // Same floor: only horizontal movement
        if (x1 == x2) {
            cout << llabs(y1 - y2) << "\n";
            continue;
        }

        ll diff = llabs(x1 - x2);
        ll ans = LLONG_MAX;

        // ---- Try stairs ----
        if (!stairs.empty()) {
            auto it = lower_bound(stairs.begin(), stairs.end(), y1);
            for (int k = 0; k < 2; k++) {
                if (it == stairs.end()) break;
                ll s = *it;
                ans = min(ans,
                          llabs(y1 - s) +
                          llabs(y2 - s) +
                          diff);
                if (it == stairs.begin()) break;
                --it;
            }
        }

        // ---- Try elevators ----
        if (!elev.empty()) {
            auto it = lower_bound(elev.begin(), elev.end(), y1);
            for (int k = 0; k < 2; k++) {
                if (it == elev.end()) break;
                ll e = *it;

                // IMPORTANT FIX:
                // You may mix stairs and elevator
                ll vert = min(diff, (diff + v - 1) / v);

                ans = min(ans,
                          llabs(y1 - e) +
                          llabs(y2 - e) +
                          vert);
                if (it == elev.begin()) break;
                --it;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
