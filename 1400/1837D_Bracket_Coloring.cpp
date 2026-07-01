#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        string s;
        cin >> n >> s;

        int openCnt = count(s.begin(), s.end(), '(');
        int closeCnt = n - openCnt;

        if (openCnt != closeCnt) {
            cout << -1 << '\n';
            continue;
        }

        int bal = 0, mn = 0, mx = 0;
        for (char c : s) {
            bal += (c == '(' ? 1 : -1);
            mn = min(mn, bal);
            mx = max(mx, bal);
        }

        if (mn >= 0 || mx <= 0) {
            cout << 1 << '\n';
            for (int i = 0; i < n; i++) {
                cout << 1 << (i + 1 == n ? '\n' : ' ');
            }
            continue;
        }

        vector<int> color(n);
        bal = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                ++bal;
                color[i] = (bal > 0 ? 1 : 2);
            } else {
                color[i] = (bal > 0 ? 1 : 2);
                --bal;
            }
        }

        cout << 2 << '\n';
        for (int i = 0; i < n; i++) {
            cout << color[i] << (i + 1 == n ? '\n' : ' ');
        }
    }

    return 0;
}