#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> robots(n);
        for (auto &x : robots) cin >> x;

        vector<int> spikes(m);
        for (auto &x : spikes) cin >> x;

        sort(spikes.begin(), spikes.end());

        // deviation range is [-k, k]
        vector<vector<int>> death_locations(2 * k + 1);
        vector<char> dead(n, 0);

        string instructions;
        cin >> instructions;

        for (int i = 0; i < n; i++) {
            auto it = lower_bound(spikes.begin(), spikes.end(), robots[i]);

            // right spike
            if (it != spikes.end()) {
                int dist = *it - robots[i];
                if (dist <= k)
                    death_locations[dist + k].push_back(i);
            }

            // left spike
            if (it != spikes.begin()) {
                --it;
                int dist = robots[i] - *it;
                if (dist <= k)
                    death_locations[-dist + k].push_back(i);
            }
        }

        int current_pos = 0;
        int alive = n;

        for (char x : instructions) {
            current_pos += (x == 'L' ? -1 : 1);

            int idx = current_pos + k;
            if (0 <= idx && idx <= 2 * k) {
                for (int i : death_locations[idx]) {
                    if (!dead[i]) {
                        dead[i] = 1;
                        alive--;
                    }
                }
                death_locations[idx].clear();
            }

            cout << alive << " ";
        }
        cout << "\n";
    }
}
