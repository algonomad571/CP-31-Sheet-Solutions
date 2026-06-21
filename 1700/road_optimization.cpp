#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, k;
    cin >> n >> l >> k;

    vector<int> positions(n);
    vector<int> times(n);

    for(int i = 0; i < n; i++) {
        cin >> positions[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> times[i];
    }

    positions.push_back(l);

    vector<int> distances(n + 1);
    for(int i = 0; i < n; i++) {
        distances[i] = positions[i + 1] - positions[i];
    }
    distances[n] = 0;

    int dp[n + 1][k + 1];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            dp[i][j] = INT_MAX;
        }
    }

    for(int j = 0; j <= k; j++) {
        dp[n][j] = 0;
    }

    for(int i = n - 1; i >= 0; i--) {
        for(int remove = 0; remove <= k; remove++) {
            int cost = 0;
            int remainingRemove = remove;

            for(int j = i + 1; j <= n && remainingRemove >= 0; j++) {
                cost += distances[j - 1];
                if (dp[j][remainingRemove] != INT_MAX) {
                    dp[i][remove] = min(dp[i][remove], times[i] * cost + dp[j][remainingRemove]);
                }
                remainingRemove--;
            }
        }
    }

    cout << dp[0][k] << "\n";

    return 0;
}
