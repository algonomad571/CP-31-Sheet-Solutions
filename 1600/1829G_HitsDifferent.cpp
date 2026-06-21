#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1500;

ll prefixSum[MAXN][MAXN];
ll answer[2000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll currentNumber = 1;

    for (int rowSum = 1; rowSum < MAXN; rowSum++) {

        for (int i = rowSum - 1; i >= 1; i--) {

            int j = rowSum - i;

            prefixSum[i][j] =
                prefixSum[i - 1][j] +
                prefixSum[i][j - 1] -
                prefixSum[i - 1][j - 1] +
                currentNumber * currentNumber;

            answer[currentNumber] = prefixSum[i][j];

            currentNumber++;
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << answer[n] << "\n";
    }

    return 0;
}