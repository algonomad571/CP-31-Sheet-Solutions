#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();

    vector<vector<int>> positions(26);
    for (int i = 0; i < n; i++) {
        positions[s1[i] - 'a'].push_back(i);
    }

    long long count = 1;   
    int pos = -1;          

    for (char c : s2) {
        auto &v = positions[c - 'a'];

        if (v.empty()) {
            cout << -1 << "\n";
            return 0;
        }

        auto it = upper_bound(v.begin(), v.end(), pos);

        if (it == v.end()) {
            count++;
            pos = v[0];
        } else {
            pos = *it;
        }
    }

    cout << count << "\n";
    return 0;
}
