#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> dp(n, 1), cnt(n, 1);
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[i] > nums[prev] && (1 + dp[prev]) > dp[i])
            {
                dp[i] = 1 + dp[prev];
                cnt[i] = cnt[prev]; // inherit prev, this is new
                // this is new because (1+dp[prev] != dp[i]).
            }
            else if (nums[i] > nums[prev] && (1 + dp[prev]) == dp[i])
            {
                cnt[i] += cnt[prev];
                // this is found another time so add whatever the prev has.
                // another time found because (1+dp[prev] == dp[i]).
            }
        }
        mx = max(mx, dp[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == mx)
        {
            ans += cnt[i];
        }
    }
    cout << ans << endl;

    return 0;
}