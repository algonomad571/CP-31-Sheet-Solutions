#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    string message;
    cin >> message;

    int ptr = 0;  

    auto match = [&](char c) {
        while (ptr < (int)message.size() && message[ptr] != c)
            ptr++;
        if (ptr == (int)message.size()) return false;
        ptr++;
        return true;
    };

    for (int i = 0; i < n; i++) {
        if (!match('<')) {
            cout << "no\n";
            return 0;
        }
        if (!match('3')) {
            cout << "no\n";
            return 0;
        }

        for (char c : words[i]) {
            if (!match(c)) {
                cout << "no\n";
                return 0;
            }
        }
    }

    if (!match('<') || !match('3')) {
        cout << "no\n";
        return 0;
    }

    cout << "yes\n";
    return 0;
}
