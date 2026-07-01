#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        vector<long long> pos;

        for (int i = 0; i < n; i++) {
            if (s[i] == '*')
                pos.push_back(i);
        }

        int k = (int)pos.size();

        if (k <= 1) {
            cout << 0 << endl;
            continue;
        }

        vector<long long> a(k);
        for (int i = 0; i < k; i++) {
            a[i] = pos[i] - i;
        }

        long long median = a[k / 2];
        long long ans = 0;

        for (int i = 0; i < k; i++) {
            ans += llabs(a[i] - median);
        }

        cout << ans << endl;
    }

    return 0;
}