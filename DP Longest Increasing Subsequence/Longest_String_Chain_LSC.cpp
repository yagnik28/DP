#include <bits/stdc++.h>
using namespace std;

// T.C => O(N*N*L) --> L = length of longest string. 
// S.C => O(N)

static bool comp(string &s1, string &s2)
{
    return s1.size() < s2.size();
}

bool checkPossible(string s1, string s2)
{
    if (s1.size() != s2.size() + 1)
    {
        return false;
    }
    int first = 0, second = 0;
    while (first < s1.size())
    {
        if ((s1[first] == s2[second]) && (second < s2.size()))
        {
            first++;
            second++;
        }
        else
        {
            first++;
        }
    }
    if (first == s1.size() && s2.size() == second)
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    sort(words.begin(), words.end(), comp);
    vector<int> dp(n, 1);
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (checkPossible(words[i], words[prev]) && ((1 + dp[prev]) > dp[i]))
            {
                dp[i] = 1 + dp[prev];
            }
        }
        mx = max(mx, dp[i]);
    }
    cout << mx << endl;

    return 0;
}