#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        ll pos;
        cin >> pos;

        int n = s.size();

        vector<int> removal_time(n);
        stack<int> st;
        int timer = 0;

        // Step 1: Compute removal times
        for (int i = 0; i < n; i++) {
            while (!st.empty() && s[st.top()] > s[i]) {
                removal_time[st.top()] = ++timer;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) {
            removal_time[st.top()] = ++timer;
            st.pop();
        }

        // Step 2: Find k using binary search
        auto getSum = [&](ll k) {
            return k * (2LL * n - k + 1) / 2;
        };

        ll l = 1, r = n, k = n;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (getSum(mid) >= pos) {
                k = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        ll prevSum = (k - 1) * (2LL * n - (k - 1) + 1) / 2;
        ll pos_in_sk = pos - prevSum;

        // Step 3: Extract answer
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (removal_time[i] >= k) {
                cnt++;
                if (cnt == pos_in_sk) {
                    cout << s[i];
                    break;
                }
            }
        }
    }

    return 0;
}