#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> mx(n + 1, 0);

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            if (x > y) swap(x, y);
            mx[y] = max(mx[y], x);
        }

        long long ans = 0;
        int cur = 0;

        for (int r = 1; r <= n; r++) {
            cur = max(cur, mx[r]);
            ans += (long long)(r - cur);
        }

        cout << ans << endl;
    }

    return 0;
}