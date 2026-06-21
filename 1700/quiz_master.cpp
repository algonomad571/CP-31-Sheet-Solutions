#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    vector<int> freq(m + 1, 0);
    int total = 0, l = 0;
    int answer = -1;

    for (int r = 0; r < n; r++) {
        // Add divisors of a[r]
        for (int d = 1; d * d <= a[r]; ++d) {
            if (a[r] % d == 0) {
                int x = d, y = a[r] / d;
                if (x <= m && freq[x]++ == 0) total++;
                if (x != y && y <= m && freq[y]++ == 0) total++;
            }
        }

        // Shrink from the left while valid
        while (l <= r) {
            bool removable = true;
            for (int d = 1; d * d <= a[l]; ++d) {
                if (a[l] % d == 0) {
                    int x = d, y = a[l] / d;
                    if ((x <= m && freq[x] == 1) || (y <= m && freq[y] == 1 && x != y)) {
                        removable = false;
                        break;
                    }
                }
            }
            if (!removable) break;

            // Remove a[l]'s divisors
            for (int d = 1; d * d <= a[l]; ++d) {
                if (a[l] % d == 0) {
                    int x = d, y = a[l] / d;
                    if (x <= m) freq[x]--;
                    if (x != y && y <= m) freq[y]--;
                }
            }
            l++;
        }

        if (total == m) {
            int diff = a[r] - a[l];
            if (answer == -1 || diff < answer)
                answer = diff;
        }
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
