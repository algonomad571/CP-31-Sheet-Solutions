#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<long long> x(n), t(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < n; ++i) cin >> t[i];

    // Initialize with extreme values based on the first person
    long long max_val = x[0] + t[0];
    long long min_val = x[0] - t[0];

    for (int i = 1; i < n; ++i) {
        max_val = max(max_val, x[i] + t[i]);
        min_val = min(min_val, x[i] - t[i]);
    }

    // The optimal x0 is the average of the maximum possible 
    // "right-reach" and minimum "left-reach" points.
    double result = (max_val + min_val) / 2.0;

    // Use fixed and setprecision to meet the 10^-6 requirement
    cout << fixed << setprecision(7) << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();    
    }
    return 0;
}