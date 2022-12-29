#include<bits/stdc++.h>
using namespace std;

/*
    Recursion : 
    T.C => >>O(2^N)
    S.C => >>O(N) --> May be go to O(target) OR go to beyond it.
*/

// Optimization
// T.C => O(N*target)
// S.C => O(target)

/*** 
    (i) Any no.of Times OR (ii) Multiple Times then do not move to next, stay on that index.
    Here, Do this for "take" part.
***/

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    vector<int> prev(target + 1, 0);
    
    // BASE CASE
    // for i = 0
    for(int T=0; T<=target; T++)
    {
        prev[T] = ((T % a[0]) == 0);
    }

    for(int i=1; i<n; i++)
    {
        vector<int> cur(target + 1, 0);
        for(int T=0; T<=target; T++)
        {
            int not_take = prev[T];
            int take = 0;
            if(T >= a[i])
            {
                take = cur[T - a[i]];
            }
            cur[T] = take + not_take;
        }
        prev = cur;
    }

    cout << prev[target] << endl;

    return 0;
}