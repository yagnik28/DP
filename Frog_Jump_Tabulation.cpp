#include<bits/stdc++.h>
using namespace std;

// Tabulation.
// Bottom-Up Approch
// See Mmeoization solution before this.

// T.C ==> O(N)
// S.C ==> O(N) + O(N) --> O(N) for recursion stack + O(N) for DP Array.
// Using prev2 for dp[i - 2], prev for dp[i-1] and cur for dp[i] we can reduce ==> S.C ==> O(N).

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> dp(n, 0);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    dp[0] = 0; // same as if(ind==0){return 0;} // prev = 0, prev2 = 0
    for(int i=1;i<n;i++)
    {
        int step_1 = dp[i - 1] + abs(a[i] - a[i - 1]); // same as step_1 line of Memoization.
        // (say) dp[i - 1] = prev
        int step_2 = INT_MAX;
        if(i - 2 >= 0)
        {
            step_2 = dp[i - 2] + abs(a[i] - a[i - 2]); // same as step_2 line of Memoization.
            // (say) dp[i - 2] = prev2 
        }
        dp[i] = min(step_1, step_2); // (say) dp[i] = cur
    }
    cout << dp[n - 1] << endl; // dp[n - 1] which is prev ==> ans = prev.

    return 0;
}