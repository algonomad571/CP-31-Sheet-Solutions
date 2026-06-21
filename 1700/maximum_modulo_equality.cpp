#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5 + 5;
ll a[N], diff[N];
ll st[N][20];
int logg[N];

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void build(int n) {
    for (int i = 1; i <= n; i++) st[i][0] = diff[i];

    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

ll query(int l, int r) {
    int j = logg[r - l + 1];
    return gcd(st[l][j], st[r - (1 << j) + 1][j]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Precompute logs
    logg[1] = 0;
    for (int i = 2; i < N; i++) {
        logg[i] = logg[i / 2] + 1;
    }

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        for (int i = 1; i <= n; i++) cin >> a[i];

        // Build diff array
        for (int i = 2; i <= n; i++) {
            diff[i] = abs(a[i] - a[i - 1]);
        }

        build(n);

        while (q--) {
            int l, r;
            cin >> l >> r;

            if (l == r) {
                cout << 0 << " ";
            } else {
                cout << query(l + 1, r) << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}