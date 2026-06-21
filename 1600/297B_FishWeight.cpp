#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    unordered_map<int, long long> diff;
    diff.reserve(n + m);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        diff[x]++;
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        diff[x]--;
    }

    vector<int> keys;
    keys.reserve(diff.size());
    for (auto &p : diff) {
        keys.push_back(p.first);
    }

    sort(keys.begin(), keys.end(), greater<int>());

    long long suffix = 0;
    for (int x : keys) {
        suffix += diff[x];
        if (suffix > 0) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
