#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<array<long long, 3>> seg(n);
    for (int i = 0; i < n; i++) {
        cin >> seg[i][0] >> seg[i][1];
        seg[i][2] = i + 1; // original index
    }

    // Sort by l ascending, r descending
    sort(seg.begin(), seg.end(), [](const array<long long,3>& a,
                                    const array<long long,3>& b) {
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    });

    long long maxR = -1;
    int idxMaxR = -1;

    for (auto &s : seg) {
        long long l = s[0];
        long long r = s[1];
        int idx = s[2];

        if (r <= maxR) {
            cout << idx << " " << idxMaxR << "\n";
            return 0;
        }

        if (r > maxR) {
            maxR = r;
            idxMaxR = idx;
        }
    }

    cout << "-1 -1\n";
    return 0;
}
