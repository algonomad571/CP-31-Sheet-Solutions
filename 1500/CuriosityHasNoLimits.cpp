#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n - 1), b(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) cin >> b[i];

    vector<int> t(n, 0);

    // Process each bit independently (only 0 and 1 bits exist)
    for (int bit = 0; bit < 2; bit++) {
        vector<int> A(n - 1), B(n - 1);
        for (int i = 0; i < n - 1; i++) {
            A[i] = (a[i] >> bit) & 1;
            B[i] = (b[i] >> bit) & 1;
        }

        bool ok = false;
        vector<int> best;

        // Try T[0] = 0 and T[0] = 1
        for (int start = 0; start <= 1 && !ok; start++) {
            vector<int> T(n, -1);
            T[0] = start;
            bool bad = false;

            for (int i = 0; i < n - 1; i++) {
                int ti = T[i];
                int ai = A[i];
                int bi = B[i];

                if (ti == 0) {
                    if (ai == 0 && bi == 0) T[i + 1] = 0;
                    else if (ai == 1 && bi == 0) T[i + 1] = 1;
                    else if (ai == 1 && bi == 1) T[i + 1] = 1;
                    else bad = true;
                } else { // ti == 1
                    if (ai == 1 && bi == 0) T[i + 1] = 0;
                    else if (ai == 1 && bi == 1) T[i + 1] = 1;
                    else bad = true;
                }

                if (bad) break;
            }

            if (!bad) {
                ok = true;
                best = T;
            }
        }

        if (!ok) {
            cout << "NO\n";
            return 0;
        }

        // Add this bit to final answer
        for (int i = 0; i < n; i++) {
            t[i] |= (best[i] << bit);
        }
    }

    cout << "YES\n";
    for (int x : t) cout << x << " ";
    cout << "\n";

    return 0;
}
