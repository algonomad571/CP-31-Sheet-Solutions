#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        // Special case
        if (n == 0) {
            cout << 1 << "\n";
            continue;
        }

        int64 ans = 1;
        while (n > 0) {
            int d = n % 10;
            // number of non-negative solutions to x+y+z=d
            ans *= (int64)(d + 2) * (d + 1) / 2;
            n /= 10;
        }

        cout << ans << "\n";
    }
    return 0;
}