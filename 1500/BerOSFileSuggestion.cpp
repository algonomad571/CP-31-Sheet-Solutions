#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<string, pair<int, string>> mp;

    for (int i = 0; i < n; i++) {
        string file;
        cin >> file;

        int len = file.size();
        unordered_set<string> seen;  

        for (int l = 0; l < len; l++) {
            for (int r = l; r < len; r++) {
                string sub = file.substr(l, r - l + 1);
                if (seen.insert(sub).second) {
                    if (mp[sub].first == 0) {
                        mp[sub].second = file;  
                    }
                    mp[sub].first++;
                }
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        string s;
        cin >> s;

        if (mp.count(s)) {
            cout << mp[s].first << " " << mp[s].second << "\n";
        } else {
            cout << "0 -\n";
        }
    }

    return 0;
}
