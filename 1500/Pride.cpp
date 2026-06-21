#include <bits/stdc++.h>
#include<numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);

    int ones = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) ones++;
    }

    if (ones > 0) {
        cout << n - ones << '\n';
        return 0;
    }

    int best = n + 1;

    for (int i = 0; i < n; i++) {
        int g = a[i];
        for (int j = i; j < n; j++) {
            g = __gcd(g, a[j]);
            if (g == 1) {
                best = min(best, j - i + 1);
                break;
            }
        }
    }

    if (best == n + 1) {
        cout << -1 << '\n';
    } else {
        cout << (best - 1) + (n - 1) << '\n';
    }

    return 0;
}
