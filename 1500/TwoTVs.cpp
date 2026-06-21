#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<long long, int>> events;
    events.reserve(2 * n);

    for (int i = 0; i < n; i++) {
        long long l, r;
        cin >> l >> r;
        events.emplace_back(l, +1);
        events.emplace_back(r, -1);
    }

    sort(events.begin(), events.end(), [](auto &a, auto &b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });

    int active = 0;
    for (auto &e : events) {
        active += e.second;
        if (active > 2) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}

