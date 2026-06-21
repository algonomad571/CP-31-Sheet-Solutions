#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m);

    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    ll g = 0;

    for (int i = 1; i < n; i++) {
        g = __gcd(g, abs(a[i] - a[0]));
    }

    for (int i = 0; i < m; i++) {
        cout << __gcd(a[0] + b[i], g) << " ";
    }
}