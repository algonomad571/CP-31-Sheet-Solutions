#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        vector<int> freq(26,0);
        for(char c: s) freq[c-'a']++;

        int best_k = 1;
        int best_keep = -1;

        for(int k=1;k<=26;k++){
            if(n%k) continue;

            int target = n/k;

            vector<int> f = freq;
            sort(f.rbegin(), f.rend());

            int keep = 0;
            for(int i=0;i<k;i++)
                keep += min(f[i], target);

            if(keep > best_keep){
                best_keep = keep;
                best_k = k;
            }
        }

        int target = n/best_k;

        vector<pair<int,int>> order;
        for(int i=0;i<26;i++)
            order.push_back({freq[i], i});

        sort(order.rbegin(), order.rend());

        vector<int> need(26,0);
        for(int i=0;i<best_k;i++)
            need[order[i].second] = target;

        string t_str = s;
        vector<int> extra;

        for(int i=0;i<n;i++){
            int c = s[i]-'a';

            if(need[c]>0){
                need[c]--;
            }else{
                extra.push_back(i);
            }
        }

        for(int c=0;c<26;c++){
            while(need[c]>0){
                int pos = extra.back();
                extra.pop_back();
                t_str[pos] = 'a'+c;
                need[c]--;
            }
        }

        int changes = n - best_keep;

        cout << changes << "\n";
        cout << t_str << "\n";
    }
}