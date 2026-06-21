#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> graph(n+1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        vector<int> a(n + 1);
        for (int j = 1; j <= n; ++j) {
            cin >> a[j];
            if (j >= 3) {
                graph[a[j - 1]].push_back(a[j]);
                indegree[a[j]]++;
            }
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    int visited = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        visited++;

        for (int neighbor : graph[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    if (visited == n)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
