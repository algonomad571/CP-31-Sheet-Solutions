#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int l, r;
};

bool check(int mid, int n, int m, const vector<Segment>& segments, const vector<int>& queries) {
    vector<int> a(n + 1, 0);
    // Apply the first 'mid' modifications
    for (int i = 0; i < mid; ++i) {
        a[queries[i]] = 1;
    }

    // Build prefix sums
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i];
    }

    // Check if any segment is beautiful
    for (int i = 0; i < m; ++i) {
        int l = segments[i].l;
        int r = segments[i].r;
        int len = r - l + 1;
        int ones = pref[r] - pref[l - 1];
        
        // Beautiful if ones > zeros -> ones > (len - ones) -> 2 * ones > len
        if (2 * ones > len) {
            return true;
        }
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Segment> segments(m);
    for (int i = 0; i < m; ++i) {
        cin >> segments[i].l >> segments[i].r;
    }

    int q;
    cin >> q;
    vector<int> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
    }

    int low = 1, high = q, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid, n, m, segments, queries)) {
            ans = mid;
            high = mid - 1; // Try to find an earlier change
        } else {
            low = mid + 1; // Need more changes
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}