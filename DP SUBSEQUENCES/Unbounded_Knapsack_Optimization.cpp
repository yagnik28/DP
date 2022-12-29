#include<bits/stdc++.h>
using namespace std;

/*
    Recursion : 
    T.C => >>O(2^N)
    S.C => >>O(N) 
*/

// Optimization : 
// T.C => O(N*W)
// S.C => O(W)

int main()
{
    int n, W;
    cin >> n >> W;
    vector<int> wt(n), val(n);
    for(int i=0;i<n;i++)
    {
        cin >> wt[i];
    }
    for(int i=0;i<n;i++)
    {
        cin >> val[i];
    }

    vector<int> prev(W + 1, 0);

    // BASE CASE
    for(int weight = wt[0]; weight <= W; weight++)
    {
        prev[weight] = ((W / wt[0])*val[0]);
    }

    for(int i=1;i<n;i++)
    {
        vector<int> cur(W + 1, 0);
        for(int weight = 0; weight <= W; weight++)
        {
            int not_take = 0 + prev[weight];
            int take = INT_MIN;
            if(weight >= wt[i])
            {
                take = val[i] + cur[weight - wt[i]];
            }
            cur[weight] = max(take, not_take);
        }
        prev = cur;
    }

    cout << prev[W] << endl;

    return 0;
}

    // Without Using "cur" array.

    /* Because for "not_take" we need same column value of "prev" (prev[weight]), 
       for "take" we need prev[weight - wt[i]],
       which is back values of "prev",
       so we don't need "cur" we can update the "prev" itself. */

    // for(int i=1;i<n;i++)
    // {
    //     vector<int> cur(W + 1, 0);
    //     for(int weight = wt[0]; weight <= W; weight++)
    //     {
    //         int not_take = 0 + prev[weight];
    //         int take = INT_MIN;
    //         if(weight >= wt[i])
    //         {
    //             take = val[i] + prev[weight - wt[i]];
    //         }
    //         prev[weight] = max(take, not_take);
    //     }
    // }