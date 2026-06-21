#include <bits/stdc++.h>
using namespace std;

using ll = long long;

static int cnt[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    const int MAXA = 1000000;

    while (t--) {
        int n;
        cin >> n;

        vector<int> vals;
        vals.reserve(n);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (cnt[x] == 0) vals.push_back(x);

            cnt[x]++;
        }

        long long ans = 0;

        for (int x : vals) {
            long long c = cnt[x];
            if (c >= 3) {
                ans += c * (c - 1) * (c - 2);
            }
        }

        for (int x : vals) {
            for (long long b = 2; 1LL * x * b * b <= MAXA; b++) {
                long long y = 1LL * x * b;
                long long z = y * b;

                if (cnt[y] && cnt[z]) {
                    ans += 1LL * cnt[x] * cnt[y] * cnt[z];
                }
            }
        }

        cout << ans << endl;

        for (int x : vals) {
            cnt[x] = 0;
        }
    }

    return 0;
}