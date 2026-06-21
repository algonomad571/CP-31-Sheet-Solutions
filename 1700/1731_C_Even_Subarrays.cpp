#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Precompute perfect squares
    const int MAXX = 1 << 18;
    vector<int> squares;
    for (int i = 0; i * i < MAXX; i++) {
        squares.push_back(i * i);
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        unordered_map<int, int> freq;
        freq.reserve(n * 2);
        freq[0] = 1;

        int px = 0;
        long long bad = 0;

        for (int i = 0; i < n; i++) {
            px ^= a[i];

            for (int s : squares) {
                int need = px ^ s;
                if (freq.count(need)) {
                    bad += freq[need];
                }
            }

            freq[px]++;
        }

        long long total = 1LL * n * (n + 1) / 2;
        cout << total - bad << '\n';
    }

    return 0;
}