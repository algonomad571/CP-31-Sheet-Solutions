#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<long long> cntA(n + 1, 0), cntB(m + 1, 0);

    for (int i = 0; i < n; ) {
        if (a[i] == 0) {
            i++;
            continue;
        }
        int j = i;
        while (j < n && a[j] == 1) j++;
        int len = j - i;
        for (int x = 1; x <= len; x++) {
            cntA[x] += (len - x + 1);
        }
        i = j;
    }

    for (int i = 0; i < m; ) {
        if (b[i] == 0) {
            i++;
            continue;
        }
        int j = i;
        while (j < m && b[j] == 1) j++;
        int len = j - i;
        for (int x = 1; x <= len; x++) {
            cntB[x] += (len - x + 1);
        }
        i = j;
    }

    long long ans = 0;

    for (long long h = 1; h * h <= k; h++) {
        if (k % h != 0) continue;
        long long w = k / h;

        if (h <= n && w <= m)
            ans += cntA[h] * cntB[w];

        if (h != w && w <= n && h <= m)
            ans += cntA[w] * cntB[h];
    }

    cout << ans << '\n';
    return 0;
}
