#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, k, z;
        cin >> n >> k >> z;

        vector<int> a(n);
        for (int &x : a) cin >> x;

        vector<int> pref(n+1);
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i-1] + a[i-1];

        int ans = 0;
        int best_pair = 0;

        for (int i = 0; i <= k; i++) {
            if (i+1 < n)
                best_pair = max(best_pair, a[i] + a[i+1]);

            for (int L = 0; L <= z; L++) {
                int moves = i + 2*L;
                if (moves > k) break;

                int pos = i;
                int score = pref[pos+1] + L * best_pair;

                ans = max(ans, score);
            }
        }

        cout << ans << "\n";
    }
}