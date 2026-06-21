#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	
	while(t--){
	    int n;
        cin>>n;

        string s;
        cin>>s;

        bool continuous_three_empty_cells=false;
        int total=0;

        for(int i=0; i<n; i++){
            if(s[i]=='.' && i+1<n && s[i+1]=='.' && i+2<n && s[i+2]=='.'){
                continuous_three_empty_cells=true;
                break;
            }
            if(s[i]=='.')total++;
        }

        if(continuous_three_empty_cells)cout<<2<<endl;
        else cout<<total<<endl;
	}
	return 0;
}
