#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        vector<vector<long long>> dp(n + 1, vector<long long>(2, INF));
Dora
        dp[0][0] = 0; // friend's turn first

        for (int i = 0; i < n; i++) {
            for (int turn = 0; turn < 2; turn++) {
                if (dp[i][turn] == INF) continue;

                for (int len = 1; len <= 2; len++) {
                    if (i + len > n) continue;

                    if (turn == 0) {
                        // friend's turn
                        long long cost = 0;
                        for (int j = i + 1; j <= i + len; j++) {
                            if (a[j] == 1) cost++;
                        }
                        dp[i + len][1] = min(dp[i + len][1],
                                              dp[i][0] + cost);
                    } else {
                        // your turn
                        dp[i + len][0] = min(dp[i + len][0],
                                              dp[i][1]);
                    }
                }
            }
        }

        cout << min(dp[n][0], dp[n][1]) << '\n';
    }

    return 0;
}
