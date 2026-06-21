#include <bits/stdc++.h>
using namespace std;

int ask(int x, int y){
    cout << "? " << x << " " << y << endl;
    cout.flush();
    int k;
    cin >> k;
    return k;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> ans(n + 1);
    int mx = 1;

    for(int i = 2; i <= n; i++){
        int x = ask(mx, i);
        int y = ask(i, mx);

        if(x > y){
            ans[mx] = x;
            mx = i;
        }
        else{
            ans[i] = y;
        }
    }

    ans[mx] = n;

    cout << "! ";
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}