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

        vector<long long> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }

        long long ans = b * x[n - 1];  // never move capital

        if (a < b) {
            for (int i = 0; i < n; i++) {
                ans = min(ans, b * x[n - 1] + a * x[i]);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
