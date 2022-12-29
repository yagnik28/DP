#include<bits/stdc++.h>
using namespace std;

// Tabulation 

// T.C ==> O(3*4*N)
// S.C ==> O(4)

// 3-TASKS ==> 0 -> Task_1 done before, 1 -> Task_2 done before, 2 -> Task_3 done before, 3 -> Not any Task done before.


int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (3));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin >> a[i][j];
        }
    }

    /*  Change from Tabulation : 
        dp[i-1] => prev; -> means no need to keep 0 to i-1 rows keep (i-1)th row only.
        dp[i] => temp; -> means no need to keep 0 to i rows, keep ith row only.
    */

    // base value.
    vector<int> prev(4, 0);
    prev[0] = max(a[0][1], a[0][2]);
    prev[1] = max(a[0][0], a[0][2]);
    prev[2] = max(a[0][0], a[0][1]);
    prev[3] = *max_element(a[0].begin(), a[0].end());

    for(int day=1;day<n;day++)
    {
        vector<int> temp(4, 0);
        for(int last=0;last<4;last++)
        {
            for(int task=0;task<3;task++)
            {
                if(task != last)
                {
                    int point = temp[task] + prev[task];
                    temp[last] = max(temp[last], point);
                }
            }
        }
    }
    cout << prev[3] << endl;


    return 0;
}