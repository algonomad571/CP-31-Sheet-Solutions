#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> v10, v01, v00;
    long long sum11 = 0;
    int x = 0;

    for (int i = 0; i < n; i++) {
        string s;
        long long w;
        cin >> s >> w;
        if (s == "11") {
            sum11 += w;
            x++;
        } else if (s == "10") v10.push_back(w);
        else if (s == "01") v01.push_back(w);
        else v00.push_back(w);
    }

    sort(v10.rbegin(), v10.rend());
    sort(v01.rbegin(), v01.rend());
    sort(v00.rbegin(), v00.rend());

    vector<long long> p10(v10.size()+1,0), p01(v01.size()+1,0), p00(v00.size()+1,0);
    for (int i = 0; i < (int)v10.size(); i++) p10[i+1] = p10[i] + v10[i];
    for (int i = 0; i < (int)v01.size(); i++) p01[i+1] = p01[i] + v01[i];
    for (int i = 0; i < (int)v00.size(); i++) p00[i+1] = p00[i] + v00[i];

    long long ans = 0;

    auto solve = [&](vector<long long>& A, vector<long long>& B,
                     vector<long long>& pA, vector<long long>& pB) {

        int lim = min(A.size(), B.size());
        for (int k = 0; k <= lim; k++) {
            int remA = A.size() - k;
            for (int d = 0; d <= min(x, remA); d++) {
                int t = min((int)v00.size(), x - d);
                long long cur = sum11
                              + pA[k + d]
                              + pB[k]
                              + p00[t];
                ans = max(ans, cur);
            }
        }
    };

    solve(v10, v01, p10, p01);
    solve(v01, v10, p01, p10); 

    cout << ans << "\n";
    return 0;
}
