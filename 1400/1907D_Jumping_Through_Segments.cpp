#include<iostream>
using namespace std;

int segmentStart[200000], segmentEnd[200000];

bool isReachable(int segmentcount, int maxJump){
    int currentmin=0, currentmax=0;

    for(int i=0; i<segmentcount; i++){
        currentmax+=maxJump;
        currentmin-=maxJump;

        int reachableStart=max(currentmin, segmentStart[i]);
        int reachableEnd=min(currentmax, segmentEnd[i]);

        if(reachableStart>reachableEnd) return false;

        currentmin=reachableStart;
        currentmax=reachableEnd;
    }
    return true;
}

void solve(){
    int segmentcount;
    cin>>segmentcount;

    for(int i=0;i<segmentcount;i++){
        cin>>segmentStart[i]>>segmentEnd[i];
    }

    int l=0, h=1e9;

    while(l<h){
        int mid=l+(h-l)/2;

        if(isReachable(segmentcount,mid)){
            h=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout<<l<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}