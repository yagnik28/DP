#include<bits/stdc++.h>
using namespace std;

// T.C ==> O(N), S.C ==> O(1).

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    int prev = a[0]; // prev = dp[0].
    int prev2 = 0;
    for(int i=1;i<n;i++)
    {
        int pick = a[i];
        if(i - 2 >= 0)
        {
            pick += prev2; // prev2 = dp[i - 2].
        }
        int not_pick = 0 + prev; // prev = dp[i - 1].
        
        int cur = max(pick, not_pick); // cur = dp[i].
        prev2 = prev;
        prev = cur;
        
    }
    cout << prev << endl;

    return 0;
}

// Tabulation.
// T.C ==> O(N), S.C ==> O(N).

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     vector<int> dp(n, -1);
//     for(int i=0;i<n;i++)
//     {
//         cin >> a[i];
//     }
//     dp[0] = a[0];
//     int neg = 0;
//     for(int i=1;i<n;i++)
//     {
//         int pick = a[i];
//         if(i - 2 >= 0)
//         {
//             pick += dp[i - 2];
//         }
//         int not_pick = 0 + dp[i - 1];
//         dp[i] = max(pick, not_pick);
//     }
//     cout << dp[n - 1] << endl;

//     return 0;
// }


