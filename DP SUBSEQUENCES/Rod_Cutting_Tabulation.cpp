#include<bits/stdc++.h>
using namespace std;

/*
    Recursion :
    T.C => >>O(2^N)
    S.C = >>O(N)
*/

// Tabulation : 
// T.C => O(N*N)
// S.C => O(N*N) 

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> dp(N, vector<int> (N+1, -1));

    // BASE CASE
    for(int n=0;n<=N;n++)
    {
        dp[0][n] = n*a[0];
    }

    for(int ind=1;ind<N;ind++)
    {
        for(int n=1;n<=N;n++)
        {
            int not_take = 0 + dp[ind - 1][n];
            int take = INT_MIN;
            int rodlegth = ind + 1;
            if(rodlegth <= n)
            {
                take = a[ind] + dp[ind][n - rodlegth];
            }
            dp[ind][n] = max(take, not_take);
        }
    }

    cout << dp[N-1][N] << endl;
    

    return 0;
}