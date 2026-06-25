#include<bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    for current player to  win either one of these cond should be satisfied : 

    i) only 1 stack is rem

    ii) 2 stacks rem with atleast one of them having 1.


    n == 1 : 1 -> 0 , 4 -> 0 if n == 1 i win..

    n == 2 : 2 1 ->  1 1 -> 0 1 -> 0 0 I WIN HERE !! , 1 1 -> 0 1 -> 0 0 I  LOSE HERE !! , 2 2 -> 2 1 -> 1 CASE => I  WIN HERE AS WELL !! 
    
    n == 2 the only place where i lose is when arr = {1 , 1}

    n == 3 : 1 1 1, 1 1 2, 1 2 2, 2 2 2
    


*/
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t; 
    while(t--){

    }
    return 0;
}
