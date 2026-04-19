#include<bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    

*/
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t; 
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        int index = -1;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                index = i;
                break;
            }
        }
        if(index == -1){
            cout << -1 << " " << -1 << endl;
            continue;
        }
        

    }
    return 0;
}
