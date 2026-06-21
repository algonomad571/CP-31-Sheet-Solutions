#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double l, d, v, g, r;
    cin >> l >> d >> v >> g >> r;

    double t = d / v;

    double cycle = g + r;
    double pos = fmod(t, cycle);

    if (pos >= g) {
        t += (cycle - pos);
    }

    t += (l - d) / v;

    cout << fixed << setprecision(9) << t << "\n";
    return 0;
}
