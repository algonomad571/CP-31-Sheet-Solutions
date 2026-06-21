#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;
const int MAXN = 1005;

long long fact[MAXN], invFact[MAXN];

long long modpow(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1) res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

long long nCr(int n,int r){
    if(r>n || r<0) return 0;
    return fact[n]*invFact[r]%MOD*invFact[n-r]%MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0]=1;
    for(int i=1;i<MAXN;i++)
        fact[i]=fact[i-1]*i%MOD;

    invFact[MAXN-1]=modpow(fact[MAXN-1],MOD-2);
    for(int i=MAXN-2;i>=0;i--)
        invFact[i]=invFact[i+1]*(i+1)%MOD;

    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        vector<int>a(n);
        for(int &x:a) cin>>x;

        sort(a.begin(),a.end(),greater<int>());

        int x=a[k-1];

        int cnt_needed=0,cnt_total=0;

        for(int i=0;i<k;i++)
            if(a[i]==x) cnt_needed++;

        for(int i=0;i<n;i++)
            if(a[i]==x) cnt_total++;

        cout<<nCr(cnt_total,cnt_needed)<<"\n";
    }
}