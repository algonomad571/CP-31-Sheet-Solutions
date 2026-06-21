#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; --i) {
        int remove_cost = 1 + dp[i + 1];
        
        int keep_cost = 1e9; 
        int next_idx = i + a[i] + 1; 
        if (next_idx <= n) {
            keep_cost = dp[next_idx];
        }

        dp[i] = min(remove_cost, keep_cost);
    }

    cout << dp[0] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

