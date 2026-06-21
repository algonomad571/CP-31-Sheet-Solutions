#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string l, r;
        cin >> l >> r;
        int n = l.size();

        if (l == r) {
            cout << 2 * n << '\n';
            continue;
        }

        int i = 0;

        while (i < n && l[i] == r[i]) {
            i++;
        }

        int ans = 2 * i;

        if (l[i] + 1 < r[i]) {
            cout << ans << '\n';
            continue;
        }

        ans += 1;

        i++;
        while (i < n) {
            if (l[i] == '9' && r[i] == '0') {
                ans += 1;
                i++;
            } else {
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
