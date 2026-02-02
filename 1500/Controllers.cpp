#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;

    long long P = 0, M = 0;
    for (char c : s) {
        if (c == '+') P++;
        else M++;
    }

    int q;
    cin >> q;
    while (q--) {
        long long a, b;
        cin >> a >> b;

        if (a == b) {
            if (P == M) cout << "YES\n";
            else cout << "NO\n";
        } else {
            long long d = a - b;
            long long rhs = -b * (P - M);

            if (rhs % d != 0) {
                cout << "NO\n";
                continue;
            }

            long long t = rhs / d;
            if (-M <= t && t <= P) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
