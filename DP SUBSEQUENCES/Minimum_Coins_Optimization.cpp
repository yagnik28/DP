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
        if(T % a[0] == 0)
        {
            prev[T] = T / a[0];
        }
        else
        {
            prev[T] = 1e9;
        }
    }

    for(int i=1; i<n; i++)
    {
        vector<int> cur(target + 1, 0);
        for(int T=0; T<=target; T++)
        {
            int not_take = 0 + prev[T];
            int take = INT_MAX;
            if(T >= a[i])
            {
                take = 1 + cur[T - a[i]];
            }
            cur[T] = min(take, not_take);
        }
        prev = cur;
    }

    int ans = prev[target];
    if(ans >= 1e9)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }

    return 0;
}