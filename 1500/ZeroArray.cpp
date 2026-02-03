#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long sum = 0;
    long long mx = 0;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }

    if (sum % 2 == 0 && mx <= sum - mx) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
