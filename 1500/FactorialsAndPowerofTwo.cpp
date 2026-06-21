#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute factorials <= 1e12
    vector<long long> fact;
    long long cur = 1;
    for (int i = 1; ; i++) {
        cur *= i;
        if (cur > 1e12) break;
        fact.push_back(cur);
    }

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        int m = fact.size();
        int ans = INT_MAX;

        // Try all subsets of factorials
        for (int mask = 0; mask < (1 << m); mask++) {
            long long sum = 0;
            int cnt = 0;

            for (int i = 0; i < m; i++) {
                if (mask & (1 << i)) {
                    sum += fact[i];
                    cnt++;
                }
            }

            if (sum > n) continue;

            long long remaining = n - sum;
            cnt += __builtin_popcountll(remaining);

            ans = min(ans, cnt);
        }

        if (ans == INT_MAX) cout << -1 << "\n";
        else cout << ans << "\n";
    }

    return 0;
}
