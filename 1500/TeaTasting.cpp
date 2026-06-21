#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];

        vector<long long> pref(n + 1, 0);
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + a[i];

        vector<long long> cnt(n + 2, 0), add(n + 2, 0);

        for (int j = 1; j <= n; j++) {
            long long cap = b[j] * j;

            int l = 1, r = j, pos = j + 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                long long need = pref[j] - pref[mid - 1];
                long long can = b[j] * (j - mid + 1);
                if (need <= can) {
                    pos = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            if (pos <= j) {
                cnt[pos]++;
                cnt[j + 1]--;
            }

            if (pos > 1) {
                long long used = b[j] * (j - pos + 1);
                long long remaining = cap - used;
                add[pos - 1] += remaining;
            }
        }

        vector<long long> ans(n + 1, 0);
        long long cur = 0;
        for (int i = 1; i <= n; i++) {
            cur += cnt[i];
            ans[i] = cur * a[i] + add[i];
        }

        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}
