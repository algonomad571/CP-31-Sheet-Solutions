#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;


int main (){
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;

        vector<int> a(n);
        vector<int> b(n);
        for(int i=0;i<n-1;++i) cin>>a[i];
        for(int i=0;i<n;++i) cin>>b[i];
        a[n-1]=1;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int p=0;

        for(int i=0;i<n;++i){
            if(b[i]>a[p]){
                p++;
            }
        }

        cout<<n-p<<endl;
    }
}