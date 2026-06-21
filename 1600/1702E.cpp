#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> adj;
vector<bool> vis;

int dfs(int u) {
    vis[u] = true;
    int len = 1;

    for (int v : adj[u]) {
        if (!vis[v]) {
            len += dfs(v);
            break; // only one path matters (degree ≤ 2)
        }
    }

    return len;
}

void solve() {
    int n;
    cin >> n;

    adj.assign(n, {});
    vis.assign(n, false);

    bool ok = true;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;

        if (x == y) ok = false;

        adj[x].push_back(y);
        adj[y].push_back(x);

        if (adj[x].size() > 2 || adj[y].size() > 2) {
            ok = false;
        }
    }

    if (!ok) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            int len = dfs(i);
            if (len % 2 == 1) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}