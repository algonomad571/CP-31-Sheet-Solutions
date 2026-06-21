#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll side_cost(ll x, ll len) {
    if (x > len) {
        return len * x - len * (len + 1) / 2;
    } else {
        return (x - 1) * x / 2 + (len - (x - 1));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;

    ll L = k - 1;
    ll R = n - k;

    ll low = 1, high = m, ans = 1;

    while (low <= high) {
        ll mid = (low + high) / 2;

        ll need = mid;
        need += side_cost(mid, L);
        need += side_cost(mid, R);

        if (need <= m) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
