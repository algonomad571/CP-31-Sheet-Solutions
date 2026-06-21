#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> R(N), C(N);
    for (int i = 0; i < N; i++) cin >> R[i];
    for (int i = 0; i < N; i++) cin >> C[i];

    vector<int> rowBlock(N);
    int rb = 0;
    rowBlock[0] = rb;
    for (int i = 1; i < N; i++) {
        if ((R[i] & 1) != (R[i - 1] & 1)) rb++;
        rowBlock[i] = rb;
    }

    vector<int> colBlock(N);
    int cb = 0;
    colBlock[0] = cb;
    for (int j = 1; j < N; j++) {
        if ((C[j] & 1) != (C[j - 1] & 1)) cb++;
        colBlock[j] = cb;
    }

    while (Q--) {
        int ra, ca, rbq, cbq;
        cin >> ra >> ca >> rbq >> cbq;
        ra--; ca--; rbq--; cbq--;

        if ((R[ra] & 1) != (R[rbq] & 1) || (C[ca] & 1) != (C[cbq] & 1)) {
            cout << "NO\n";
            continue;
        }

        if (rowBlock[ra] == rowBlock[rbq] &&
            colBlock[ca] == colBlock[cbq]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}