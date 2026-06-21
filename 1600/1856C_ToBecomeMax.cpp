#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool possible(vector<ll>& a, ll k, ll x) {
    int n = a.size();

    for (int i = 0; i < n; i++) {
        ll need = x;
        ll cost = 0;

        for (int j = i; j < n; j++) {
            if (need <= a[j]) break;

            if (j == n - 1) { // cannot push further
                cost = k + 1;
                break;
            }

            cost += need - a[j];
            if (cost > k) break;

            need--;
        }

        if (cost <= k) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        for (auto &x : a) cin >> x;

        ll lo = 0;
        ll hi = *max_element(a.begin(), a.end()) + k;
        ll ans = 0;

        while (lo <= hi) {
            ll mid = (lo + hi) / 2;

            if (possible(a, k, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        cout << ans << "\n";
    }
}