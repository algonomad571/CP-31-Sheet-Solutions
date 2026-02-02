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

        vector<long long> x(n), y(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        long long lx, rx, ly, ry;

        if (n % 2 == 1) {
            lx = rx = x[n / 2];
            ly = ry = y[n / 2];
        } else {
            lx = x[n / 2 - 1];
            rx = x[n / 2];
            ly = y[n / 2 - 1];
            ry = y[n / 2];
        }

        long long result = (rx - lx + 1) * (ry - ly + 1);
        cout << result << '\n';
    }

    return 0;
}
