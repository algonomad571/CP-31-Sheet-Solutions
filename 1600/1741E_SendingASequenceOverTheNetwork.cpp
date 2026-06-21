#include <iostream>
#include <vector>
using namespace std;

bool solve() {
    int n;
    cin >> n;
    vector<long long> b(n + 1);
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        if (i + b[i] <= n && dp[i - 1]) {
            dp[i + b[i]] = true;
        }
        if (i - b[i] - 1 >= 0 && dp[i - b[i] - 1]) {
            dp[i] = true;
        }
    }
    return dp[n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        if (solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
