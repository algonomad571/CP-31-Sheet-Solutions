#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long a, b;
        cin >> n >> a >> b;

        vector<long long> c(n);
        for (int i = 0; i < n; i++) cin >> c[i];

        long long g = __gcd(a, b);

        if (g == 0) {
            long long mn = *min_element(c.begin(), c.end());
            long long mx = *max_element(c.begin(), c.end());
            cout << mx - mn << '\n';
            continue;
        }

        vector<long long> r;
        for (long long x : c)
            r.push_back(x % g);

        sort(r.begin(), r.end());

        int sz = r.size();
        vector<long long> ext = r;
        for (int i = 0; i < sz; i++)
            ext.push_back(r[i] + g);

        long long ans = LLONG_MAX;
        for (int i = 0; i + sz - 1 < (int)ext.size(); i++) {
            ans = min(ans, ext[i + sz - 1] - ext[i]);
        }

        cout << ans << '\n';
    }
    return 0;
}
