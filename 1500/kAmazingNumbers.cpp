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

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<vector<int>> pos(n + 1);
        for (int i = 1; i <= n; i++) {
            pos[a[i]].push_back(i);
        }

        const int INF = 1e9;
        vector<int> best(n + 2, INF);

        for (int x = 1; x <= n; x++) {
            if (pos[x].empty()) continue;

            int max_gap = pos[x][0] - 1;  
            for (int i = 1; i < (int)pos[x].size(); i++) {
                max_gap = max(max_gap, pos[x][i] - pos[x][i - 1] - 1);
            }
            max_gap = max(max_gap, n - pos[x].back()); 

            int need = max_gap + 1;
            if (need <= n) {
                best[need] = min(best[need], x);
            }
        }

        int cur = INF;
        for (int k = 1; k <= n; k++) {
            cur = min(cur, best[k]);
            if (cur == INF) cout << -1 << " ";
            else cout << cur << " ";
        }
        cout << '\n';
    }

    return 0;
}
