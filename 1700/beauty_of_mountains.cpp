#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int computeGCD(long long a, long long b)
{
    return b==0 ? a: computeGCD(b,a%b);
}
void solve ()
{
    int n,m,k;
        cin>>n>>m>>k;

        vector<vector<int>> height(n, vector<int>(m));
        vector<string> type(n);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> height[i][j];

        for (int i = 0; i < n; ++i)
            cin >> type[i];

        long long difference=0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (type[i][j] == '1')  // without snowy cap
                    difference += height[i][j];
                else                    // with snowy cap
                    difference -= height[i][j];

        difference = abs(difference);

        vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int val = (type[i - 1][j - 1] == '1') ? 1 : -1;
                prefix[i][j] = val + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }

        long long g = 0;
        for (int i = 1; i <= n - k + 1; ++i) {
            for (int j = 1; j <= m - k + 1; ++j) {
                int x1 = i, y1 = j;
                int x2 = i + k - 1, y2 = j + k - 1;
                int sum = prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];
                g = computeGCD(g, abs(sum));
            }
        }

        if (difference == 0)
        cout << "YES\n";
        else if (g == 0)
            cout << "NO\n";
        else
            cout << (difference % g == 0 ? "YES\n" : "NO\n");
}

int main ()
{
    int t;
    cin>>t;

    while(t--)
    {
        solve();
    }
    return 0;
}
