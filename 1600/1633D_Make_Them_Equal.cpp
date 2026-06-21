#include <bits/stdc++.h>
using namespace std;

const int MAXB = 1000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> cost(MAXB + 1, 1e9);
    cost[1] = 0;

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int x = 1; x <= v; x++) {
            int nv = v + v / x;
            if (nv > MAXB) continue;

            if (cost[nv] > cost[v] + 1) {
                cost[nv] = cost[v] + 1;
                q.push(nv);
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> b(n), c(n);
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];

        vector<int> w(n);
        int sumW = 0;
        for (int i = 0; i < n; i++) {
            w[i] = cost[b[i]];
            sumW += w[i];
        }

        k = min(k, sumW);

        vector<int> dp(k + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int j = k; j >= w[i]; j--) {
                dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
            }
        }

        cout << *max_element(dp.begin(), dp.end()) << '\n';
    }

    return 0;
}