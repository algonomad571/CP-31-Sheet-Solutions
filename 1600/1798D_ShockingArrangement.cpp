#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> pos, neg;
        long long x;

        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x >= 0) pos.push_back(x);
            else neg.push_back(x);
        }

        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());

        vector<long long> ans;
        int i = pos.size() - 1;
        int j = 0;

        long long sum = 0;

        while (i >= 0 || j < neg.size()) {

            if (sum <= 0) {
                if (i >= 0) {
                    ans.push_back(pos[i]);
                    sum += pos[i];
                    i--;
                } else {
                    ans.push_back(neg[j]);
                    sum += neg[j];
                    j++;
                }
            } 
            else {
                if (j < neg.size()) {
                    ans.push_back(neg[j]);
                    sum += neg[j];
                    j++;
                } else {
                    ans.push_back(pos[i]);
                    sum += pos[i];
                    i--;
                }
            }
        }

        long long mx = *max_element(ans.begin(), ans.end());
        long long mn = *min_element(ans.begin(), ans.end());

        long long pref = 0, maxpref = 0, minpref = 0;

        for (auto v : ans) {
            pref += v;
            maxpref = max(maxpref, pref);
            minpref = min(minpref, pref);
        }

        if (maxpref - minpref >= mx - mn) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            for (auto v : ans) cout << v << " ";
            cout << "\n";
        }
    }
}