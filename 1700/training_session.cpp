#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long solve() {
    long long n;
    cin >> n;

    vector<int> a(n), b(n);
    map<int, int> freqA, freqB;

    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        freqA[a[i]]++;
        freqB[b[i]]++;
    }

    long long bad = 0;
    for (int i = 0; i < n; ++i) {
        bad += 1LL* (freqA[a[i]] - 1) * (freqB[b[i]] - 1);
    }

    long long total = n * (n - 1) * (n - 2) / 6;

    return total - bad;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }

    return 0;
}
