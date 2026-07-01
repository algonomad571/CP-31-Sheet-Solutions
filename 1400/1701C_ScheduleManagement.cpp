#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> cnt;
int n, m;

bool can(int t) {
    ll need = 0;
    ll extra = 0;

    for (int i = 1; i <= n; i++) {
        if (cnt[i] > t) {
            need += cnt[i] - t;
        } else {
            extra += (t - cnt[i]) / 2;
        }
    }

    return extra >= need;
}

void solve() {
    cin >> n >> m;

    cnt.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int l = 0, r = 2 * m;
    int ans = r;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (can(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;
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