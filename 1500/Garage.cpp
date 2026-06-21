#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll count_suitable(ll x) {
    if (x <= 0) return 0;
    ll bad_mod2 = (x + 2) / 4; 
    ll bad = bad_mod2;
    if (x >= 1) bad++; 
    if (x >= 4) bad++; 
    return x - bad;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;

    ll lo = 1, hi = 2e18, ans = -1;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (count_suitable(mid) >= N) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
