#include<bits/stdc++.h>
using namespace std;

// Tabulation 

// T.C ==> O(3*4*N)
// S.C ==> O(3*N)

// 3-TASKS ==> 0 -> Task_1 done before, 1 -> Task_2 done before, 2 -> Task_3 done before, 3 -> Not any Task done before.


int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (3));
    vector<vector<int>> dp(n, vector<int> (4, 0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin >> a[i][j];
        }
    }
    // base value.
    dp[0][0] = max(a[0][1], a[0][2]);
    dp[0][1] = max(a[0][0], a[0][2]);
    dp[0][2] = max(a[0][0], a[0][1]);
    dp[0][3] = *max_element(a[0].begin(), a[0].end());

    for(int day=1;day<n;day++)
    {
        for(int last=0;last<4;last++)
        {
            for(int task=0;task<3;task++)
            {
                if(task != last)
                {
                    int point = a[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    cout << dp[n - 1][3] << endl;


    return 0;
}