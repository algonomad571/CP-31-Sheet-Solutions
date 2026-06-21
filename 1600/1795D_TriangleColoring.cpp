#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

ll modpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];

    ll ways = 1;

    for (int i = 0; i < n; i += 3) {
        ll a = w[i];
        ll b = w[i+1];
        ll c = w[i+2];

        ll s1 = a + b;
        ll s2 = a + c;
        ll s3 = b + c;

        ll mx = max({s1, s2, s3});
        int cnt = 0;

        if (s1 == mx) cnt++;
        if (s2 == mx) cnt++;
        if (s3 == mx) cnt++;

        ways = ways * cnt % MOD;
    }

    int m = n / 3;

    vector<ll> fact(m+1), invfact(m+1);
    fact[0] = 1;

    for (int i = 1; i <= m; i++)
        fact[i] = fact[i-1] * i % MOD;

    invfact[m] = modpow(fact[m], MOD-2);

    for (int i = m; i > 0; i--)
        invfact[i-1] = invfact[i] * i % MOD;

    auto C = [&](int n, int r) {
        return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
    };

    ll choose = C(m, m/2);

    cout << ways * choose % MOD << "\n";
}