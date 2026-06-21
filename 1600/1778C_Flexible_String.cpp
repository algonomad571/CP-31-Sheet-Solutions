#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string a, b;
        cin >> a >> b;

        // Unique chars in a
        set<char> st(a.begin(), a.end());
        vector<char> chars(st.begin(), st.end());
        int m = chars.size();

        // Map char -> index
        unordered_map<char, int> id;
        for (int i = 0; i < m; i++) {
            id[chars[i]] = i;
        }

        ll ans = 0;

        for (int mask = 0; mask < (1 << m); mask++) {
            if (__builtin_popcount(mask) > k) continue;

            ll cur = 0, len = 0;

            for (int i = 0; i < n; i++) {
                if (a[i] == b[i] || (mask & (1 << id[a[i]]))) {
                    len++;
                } else {
                    cur += len * (len + 1) / 2;
                    len = 0;
                }
            }

            cur += len * (len + 1) / 2;
            ans = max(ans, cur);
        }

        cout << ans << '\n';
    }

    return 0;
}