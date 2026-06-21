#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        // Step 1: Check same elements
        vector<int> sa = a, sb = b;
        sort(sa.begin(), sa.end());
        sort(sb.begin(), sb.end());

        if (sa != sb) {
            cout << "NO\n";
            continue;
        }

        // Step 2: Build position map for b
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[b[i]] = i;
        }

        // Step 3: Build permutation
        vector<bool> vis(n, false);
        int cycles = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cycles++;
                int cur = i;
                while (!vis[cur]) {
                    vis[cur] = true;
                    cur = pos[a[cur]];
                }
            }
        }

        int parity = (n - cycles) % 2;

        if (parity == 0) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}