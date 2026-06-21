#include <iostream>
using namespace std;

const int MAXN = 1000005;
bool isPrime[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int limit = n + 2;

    for (int i = 2; i <= limit; i++) isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }

    if (n == 1) {
        cout << 1 << "\n1\n"; 
        return 0;
    }

    if (n == 2) {
        cout << 1 << "\n1 1\n";
        return 0;
    }

    cout << 2 << "\n"; 
    for (int i = 2; i <= n + 1; i++) {
        if (isPrime[i]) cout << 2 << " ";
        else cout << 1 << " ";
    }
    cout << "\n";

    return 0;
}
