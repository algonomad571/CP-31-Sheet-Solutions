#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
vector<int> adj[N];
int depth[N], subtree[N];

void dfs(int u, int p) {
    subtree[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        subtree[u] += subtree[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) adj[i].clear();

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 0;
    dfs(1, 0);

    vector<long long> val;

    for (int i = 1; i <= n; i++) {
        val.push_back((long long)depth[i] - (subtree[i] - 1));
    }

    sort(val.rbegin(), val.rend());

    long long ans = 0;
    for (int i = 0; i < k; i++) {
        ans += val[i];
    }

    cout << ans << "\n";
}