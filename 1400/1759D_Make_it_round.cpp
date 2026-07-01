#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, m;
    cin >> n >> m;

    long long temp = n;

    int cnt2 = 0, cnt5 = 0;

    while (temp % 2 == 0) {
        cnt2++;
        temp /= 2;
    }

    while (temp % 5 == 0) {
        cnt5++;
        temp /= 5;
    }

    long long k = 1;

    while (cnt2 < cnt5 && k * 2 <= m) {
        k *= 2;
        cnt2++;
    }

    while (cnt5 < cnt2 && k * 5 <= m) {
        k *= 5;
        cnt5++;
    }

    while (k * 10 <= m) {
        k *= 10;
    }

    k *= (m / k);

    cout << n * k << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();
}