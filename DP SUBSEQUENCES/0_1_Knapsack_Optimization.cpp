#include<bits/stdc++.h>
using namespace std;

/*
    Recursion : 
    T.C => O(2^N)
    S.C => O(N)
*/

// Tabulation : 
// T.C => O(N*K)
// S.C => O(K)

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
    vector<int> cur(W + 1); 

    // BASE CASE
    // for i = 0
    // weight starts from wt[0], not starts form 0.
    for(int i = wt[0]; i <= W; i++)
    {
        prev[i] = val[0];
    }

    for(int i = 1; i < n; i++)
    {
        for(int weight = 0; weight <= W; weight++)
        {
            int not_take = 0 + prev[weight];
            int take = INT_MIN;
            if(weight >= wt[i])
            {
                take = val[i] + prev[weight - wt[i]];
            }
            cur[weight] = max(take, not_take);
        }
        prev = cur;
    }

    cout << prev[W] << endl;


    /*** Without Using 'cur' ***/

    // CHANGE : 'weight' for loop reversed. because we only need prev row, donesn't need same row's element, 
    //           So we can run it in any direction.

    // for(int i = 1; i < n; i++)
    // {
    //     for(int weight = W; weight >= 0; weight--)
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

    return 0;
}