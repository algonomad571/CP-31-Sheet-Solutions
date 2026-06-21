#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(const vector<ll>& y) {
    int n = y.size();
    vector<bool> on_first(n);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((ll)i * (y[j] - y[0]) == (ll)j * (y[i] - y[0]))
                on_first[j] = true;
            else
                on_first[j] = false;
        }

        int idx = -1;
        bool ok = true;

        for (int j = 0; j < n; j++) {
            if (!on_first[j]) {
                if (idx == -1) {
                    idx = j;  
                } else {
                    if ((ll)i * (y[j] - y[idx]) != (ll)(j - idx) * (y[i] - y[0])) {
                        ok = false;
                        break;
                    }
                }
            }
        }

        if (ok && idx != -1)
            return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> y(n);
    for (int i = 0; i < n; i++) cin >> y[i];

    bool ans = false;
    ans |= check(y);                 
    reverse(y.begin(), y.end());
    ans |= check(y);                 

    cout << (ans ? "Yes\n" : "No\n");
    return 0;
}
