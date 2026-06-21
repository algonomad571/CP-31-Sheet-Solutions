#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(const vector<int>& a, const vector<int>& b, int mid) {
    int n = a.size();
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (mid - 1 - a[i] <= cnt && cnt <= b[i]) {
            cnt++;
        }
    }

    return cnt >= mid;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    int lo = -1, hi = n + 1;

    while (hi - lo > 1) {
        int mid = (lo + hi) >> 1;

        if (check(a, b, mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << lo << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}