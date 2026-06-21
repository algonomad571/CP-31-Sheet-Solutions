#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        // dp[pos][age][dir]
        // dir = 0 -> left, 1 -> right
        vector<vector<array<int, 2>>> dp(n, vector<array<int, 2>>(k));

        // base: age = 1
        for (int i = 0; i < n; i++) {
            dp[i][0][0] = dp[i][0][1] = 1;
        }

        for (int age = 1; age < k; age++) {
            // moving right -> process from right to left
            for (int i = n - 1; i >= 0; i--) {
                int from_same = (i + 1 < n) ? dp[i + 1][age][1] : 1;
                int from_reflect = (i - 1 >= 0) ? dp[i - 1][age - 1][0] : 1;

                dp[i][age][1] = (from_same + from_reflect) % MOD;
            }

            // moving left -> process from left to right
            for (int i = 0; i < n; i++) {
                int from_same = (i - 1 >= 0) ? dp[i - 1][age][0] : 1;
                int from_reflect = (i + 1 < n) ? dp[i + 1][age - 1][1] : 1;

                dp[i][age][0] = (from_same + from_reflect) % MOD;
            }
        }

        cout << dp[0][k - 1][1] << '\n';
    }

    return 0;
}