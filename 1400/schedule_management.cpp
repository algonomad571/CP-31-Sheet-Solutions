#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll n, m;
        cin >> n >> m;

        vector<int> assigned(m);
        vector<ll> taskCount(n, 0);

        for (int &x : assigned) {
            cin >> x;
            x--;  
            taskCount[x]++;
        }

        ll low = 0, high = 2 * m;

        while (low + 1 < high) {
            ll mid = (low + high) / 2;
            ll completed = 0;

            for (int i = 0; i < n; i++) {
                ll directWork = min(taskCount[i], mid);
                completed += directWork;

                completed += (mid - directWork) / 2;
            }

            if (completed >= m) {
                high = mid;
            } else {
                low = mid;
            }
        }

        cout << high << "\n";
    }

    return 0;
}
