#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<int> days = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    map<string, int> freq;

    for (int i = 0; i + 9 < (int)s.size(); i++) {
        if (!isdigit(s[i]) || !isdigit(s[i+1])) continue;
        if (s[i+2] != '-') continue;
        if (!isdigit(s[i+3]) || !isdigit(s[i+4])) continue;
        if (s[i+5] != '-') continue;
        for (int j = 6; j <= 9; j++)
            if (!isdigit(s[j + i])) goto skip;

        {
            int day   = (s[i]-'0')*10 + (s[i+1]-'0');
            int month = (s[i+3]-'0')*10 + (s[i+4]-'0');
            int year  = stoi(s.substr(i+6, 4));

            if (year < 2013 || year > 2015) continue;
            if (month < 1 || month > 12) continue;
            if (day < 1 || day > days[month]) continue;

            string date = s.substr(i, 10);
            freq[date]++;
        }
        skip:;
    }

    string ans;
    int best = 0;
    for (auto &p : freq) {
        if (p.second > best) {
            best = p.second;
            ans = p.first;
        }
    }

    cout << ans << "\n";
    return 0;
}
