#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll S;
    cin >> n >> S;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int low = 0, high = n;
    ll bestCost = 0;
    int bestK = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        vector<ll> costs(n);

        for (int i = 0; i < n; i++) {
            costs[i] = a[i] + (ll)(i + 1) * mid;
        }

        nth_element(costs.begin(), costs.begin() + mid, costs.end());
        ll sum = 0;
        for (int i = 0; i < mid; i++) {
            sum += costs[i];
        }

        if (sum <= S) {
            bestK = mid;
            bestCost = sum;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << bestK << " " << bestCost << "\n";
    return 0;
}
