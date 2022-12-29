#include <bits/stdc++.h>
using namespace std;

// Tabulation
// T.C => O(N*N)
// S.C => O(N)

bool isPalindrome(int i, int j, string s)
{
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
} 


int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> dp(n + 1, 0);
    // base case
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int mn = 1e9;
        for (int j = i; j <= n - 1; j++)
        {
            if (isPalindrome(i, j, str))
            {
                int cost = 1 + dp[j + 1];
                mn = min(mn, cost);
            }
        }
        dp[i] = mn;
    }
    cout << dp[0] - 1 << endl;

    return 0;
}