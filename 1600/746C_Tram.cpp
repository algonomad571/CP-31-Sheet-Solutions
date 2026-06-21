#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, x1, x2;
    cin >> s >> x1 >> x2;

    int t1, t2;
    cin >> t1 >> t2;

    int p, d;
    cin >> p >> d;

    long long walk = 1LL * abs(x2 - x1) * t2;

    long long L = 2LL * s;
    long long start = (d == 1 ? p : 2LL * s - p);

    long long ans = walk;

    vector<long long> board = {x1, 2LL * s - x1};
    vector<long long> target = {x2, 2LL * s - x2};

    for (long long b : board) {
        long long d1 = (b - start + L) % L;
        for (long long t : target) {
            long long d2 = (t - b + L) % L;
            long long tram_time = (d1 + d2) * t1;
            ans = min(ans, tram_time);
        }
    }

    cout << ans << "\n";
    return 0;
}
