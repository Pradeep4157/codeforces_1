#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    its more of like take / not take..

    if i take this and this thing does not

    match b[j] then it is 1*i + 1,j + 1

    but its a subs for a..

    if i take then  it is *

    else it is += ?


    is it like if s[i] is not present

    in t then i can take all the

    poss left and all poss rights

    and add that..

    else
        not possible ?


    bab
    aba

    it will return  0 but ans is 1

    because bab is not present..

    so where is j present also

    matters..


    there are some factors.. 

    whether or not i have proved that 

    these 2 are not equal.. 

    whether i am starting a new string

    or continuing with prev one.. 

    if i am continuing. 


    i am some i and some j 

    they both are not equal.

    now i need to prove that  there 
    
    is no j ahead that has same char

    as i.. 

    if i prove that then i can do 

    all the ends from i...n - 1.. 

    else we will have to  try for i + 1,j










*/
int n, m;
string s, t;
int recursion(int i, int j, bool found)
{
    if (i >= n || j >= m)
    {
        if (found == false)
            return 0;
        else
            return 1;
    }
    int res = 0;
    if(s[i] == t[j]){
        res += recursion(i + 1,j + 1,found);

    }
    else{
        res += recursion(i + 1,j + 1,1);
        
        
    }
    res += recursion(i + 1,j + 1,0);
    

    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s >> t;
    n = s.size();
    m = t.size();
    int res = recursion(0, 0, 0);
    cout << res << endl;
    return 0;
}
