#include<bits/stdc++.h>
using namespace std;

// Algorithm
// T.C => O(N*N)
// S.C => O(N)

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> dp(n, 1); // every element has 1-length LIS which is that element itself.

    int mx = 0;
    for(int i=0;i<=n-1;i++)
    {
        for(int prev=0;prev<=i-1;prev++)
        {
            if(nums[i] > nums[prev])
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        mx = max(mx, dp[i]);
    }
    cout << mx << endl;

    return 0;
}