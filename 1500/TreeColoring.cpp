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

        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // BFS to compute depths
        vector<int> depth(n + 1, -1);
        queue<int> q;
        q.push(1);
        depth[1] = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (depth[v] == -1) {
                    depth[v] = depth[u] + 1;
                    q.push(v);
                }
            }
        }

        unordered_map<int, int> cnt;
        int max_ti = 0;

        for (int i = 1; i <= n; i++) {
            cnt[depth[i]]++;
            max_ti = max(max_ti, cnt[depth[i]]);
        }

        int answer = max_ti;
        for (auto &p : cnt) {
            answer = max(answer, p.second + 1);
        }

        cout << answer << "\n";
    }
    return 0;
}
