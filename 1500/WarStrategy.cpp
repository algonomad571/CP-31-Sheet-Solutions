#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n, m, k;
        cin >> n >> m >> k;

        // Ensure left side >= right side
        if (k - 1 < n - k) {
            k = n + 1 - k;
        }

        ll a = 0, b = 0; // a = left, b = right

        while (true) {
            bool moved = false;

            // Try extend right
            if (b < n - k) {
                ll nb = b + 1;
                if (a + nb + max(a, nb) - 1 <= m) {
                    b++;
                    moved = true;
                }
            }

            // Try extend left
            if (a < k - 1) {
                ll na = a + 1;
                if (na + b + max(na, b) - 1 <= m) {
                    a++;
                    moved = true;
                }
            }

            if (!moved) break;
        }

        cout << a + b + 1 << '\n';
    }
    return 0;
}
