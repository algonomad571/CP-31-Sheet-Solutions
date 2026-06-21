#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 200005;
int log_table[MAXN + 1];
int st[MAXN][26];

void build_table(const vector<int>& a, int m) {
    for (int i = 0; i < m; ++i) {
        st[i][0] = a[i];
    }

    log_table[1] = 0;
    for (int i = 2; i <= MAXN; ++i) {
        log_table[i] = log_table[i / 2] + 1;
    }

    for (int j = 1; (1 << j) <= m; ++j) {
        for (int i = 0; i + (1 << j) <= m; ++i) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query_max(int l, int r) {
    int j = log_table[r - l + 1];
    return max(st[l][j], st[r - (1 << j) + 1][j]);
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    build_table(a, m);

    int q;
    cin >> q;
    while (q--) {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;

        if (abs(x1 - x2) % k != 0 || abs(y1 - y2) % k != 0) {
            cout << "NO\n";
            continue;
        }

        int max_row = x2 + ((n - x2) / k) * k;

        int left = min(y1, y2) - 1;
        int right = max(y1, y2) - 1;

        int tallest_building = query_max(left, right);

        if (tallest_building < max_row) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
