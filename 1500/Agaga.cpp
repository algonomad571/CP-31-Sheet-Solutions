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

        long long x = 0;
        for (int i = 0; i < n; i++) {
            long long a;
            cin >> a;
            x ^= a;
        }

        if (x == 0 || (n & 1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
