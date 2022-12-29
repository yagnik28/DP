#include<bits/stdc++.h>
using namespace std;

//Memoization.
// Top-Down Approch

// T.C ==> O(N)
// S.C ==> O(N) + O(N) --> O(N) for recursion stack + O(N) for DP Array.
int min_energy(int ind, vector<int> &dp, vector<int> a)
{
    if(ind == 0)
    {
        return 0;
    }
    if(dp[ind] != (-1))
    {
        return dp[ind];
    }
    int step_1 = min_energy(ind - 1, dp, a) + abs(a[ind] - a[ind - 1]);
    int step_2 = INT_MAX;
    if(ind - 2 >= 0)
    {
        step_2 = min_energy(ind - 2, dp, a) + abs(a[ind] - a[ind - 2]);
    }
    return dp[ind] = min(step_1, step_2);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> dp(n+1, -1);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cout << min_energy(n-1, dp, a) << endl;

    return 0;
}