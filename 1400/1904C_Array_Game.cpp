#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    long long k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    ll ans = a[0];

    if (k >= 3) {
        cout << 0 << endl;
        return;
    }

    // k = 1 or 2
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll d = a[j] - a[i];

            ans = min(ans, d);

            if (k == 2) {
                auto it = lower_bound(a.begin(), a.end(), d);

                if (it != a.end())
                    ans = min(ans, abs(*it - d));

                if (it != a.begin()) {
                    --it;
                    ans = min(ans, abs(*it - d));
                }
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}