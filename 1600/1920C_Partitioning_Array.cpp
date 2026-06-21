#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> divisors;
        for (int d = 1; d * d <= n; d++) {
            if (n % d == 0) {
                divisors.push_back(d);
                if (d * d != n) divisors.push_back(n / d);
            }
        }

        int answer = 0;

        for (int k : divisors) {
            int g = 0;

            for (int start = 0; start < k; start++) {
                int col_g = 0;
                for (int i = start + k; i < n; i += k) {
                    col_g = __gcd(col_g, abs(a[i] - a[start]));
                }
                g = __gcd(g, col_g);
            }

            if (g != 1) answer++;
        }

        cout << answer << "\n";
    }
    return 0;
}