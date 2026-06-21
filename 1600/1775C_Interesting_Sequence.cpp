#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n, x;
        cin >> n >> x;

        // Necessary condition
        if ((n & x) != x) {
            cout << -1 << '\n';
            continue;
        }

        ll lb = n;                 // minimum m required
        ll ub = (ll)5e18;          // maximum allowed m

        for (int i = 0; i < 61; i++) {
            ll bit = (1LL << i);

            bool n_bit = (n & bit);
            bool x_bit = (x & bit);

            // First number >= n where this bit becomes 0
            ll next_zero = ((n >> (i + 1)) + 1) << (i + 1);

            if (x_bit) {
                // must stay 1 throughout
                if (!n_bit) {
                    ub = -1;
                    break;
                }
                ub = min(ub, next_zero - 1);
            } else {
                // must become 0 somewhere
                if (n_bit) {
                    lb = max(lb, next_zero);
                }
            }
        }

        if (lb <= ub) cout << lb << '\n';
        else cout << -1 << '\n';
    }

    return 0;
}