#include <bits/stdc++.h>
using namespace std;

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<int>> graph(nodes + 1);
    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    vector<int> order;
    vector<char> seen(nodes + 1, 0);

    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(1);
    seen[1] = 1;

    while (!minHeap.empty()) {
        int node = minHeap.top();
        minHeap.pop();

        order.push_back(node);

        for (auto nxt : graph[node]) {
            if (!seen[nxt]) {
                seen[nxt] = 1;
                minHeap.push(nxt);
            }
        }
    }

    for (int x : order) cout << x << " ";
    return 0;
}
