#include <bits/stdc++.h>
using namespace std;

// Tabulation
// T.C => O(N*K)
// S.C => O(N)

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> dp(n + 1, 0);
    // base case
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int len = 0, mx = 0, mx_ans = 0;
        for (int j = i; j <= min(n - 1, (i + k - 1)); j++)
        {
            len++;
            mx = max(mx, arr[j]);
            int sum = (len * mx) + dp[j + 1];
            mx_ans = max(mx_ans, sum);
        }
        dp[i] = mx_ans;
    }
    cout << dp[0] << endl;

    return 0;
}