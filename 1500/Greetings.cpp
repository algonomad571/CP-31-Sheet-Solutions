// #include <bits/stdc++.h>
// using namespace std;

// struct Fenwick {
//     int n;
//     vector<long long> bit;
//     Fenwick(int n) : n(n), bit(n + 1, 0) {}

//     void add(int i, long long v) {
//         for (; i <= n; i += i & -i)
//             bit[i] += v;
//     }

//     long long sum(int i) {
//         long long s = 0;
//         for (; i > 0; i -= i & -i)
//             s += bit[i];
//         return s;
//     }
// };

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;

//         vector<pair<long long, long long>> people(n);
//         for (int i = 0; i < n; i++)
//             cin >> people[i].first >> people[i].second;

//         sort(people.begin(), people.end());

//         vector<long long> bvals;
//         for (auto &p : people) bvals.push_back(p.second);
//         sort(bvals.begin(), bvals.end());
//         bvals.erase(unique(bvals.begin(), bvals.end()), bvals.end());

//         Fenwick fw(bvals.size());
//         long long greetings = 0;

//         for (auto &p : people) {
//             int b_idx = lower_bound(bvals.begin(), bvals.end(), p.second) - bvals.begin() + 1;

//             greetings += fw.sum(bvals.size()) - fw.sum(b_idx);

//             fw.add(b_idx, 1);
//         }

//         cout << greetings << "\n";
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

long long merge_count(vector<long long>& a, vector<long long>& temp, int l, int r) {
    if (l >= r) return 0;

    int mid = (l + r) / 2;
    long long inv = 0;

    inv += merge_count(a, temp, l, mid);
    inv += merge_count(a, temp, mid + 1, r);

    int i = l, j = mid + 1, k = l;

    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            inv += (mid - i + 1);  // key line
        }
    }

    while (i <= mid) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

    for (int p = l; p <= r; p++)
        a[p] = temp[p];

    return inv;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<pair<long long, long long>> people(n);
        for (int i = 0; i < n; i++)
            cin >> people[i].first >> people[i].second;

        // Sort by starting point
        sort(people.begin(), people.end());

        // Extract b's
        vector<long long> b(n), temp(n);
        for (int i = 0; i < n; i++)
            b[i] = people[i].second;

        cout << merge_count(b, temp, 0, n - 1) << "\n";
    }
    return 0;
}
