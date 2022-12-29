#include<bits/stdc++.h>
using namespace std;
#define int long long

// T.C => O(m*n)
// S.C => O(n)

int32_t main()
{
    int m, n;
    cin >> m >> n; // m -> rows, n -> colums 

    vector<vector<int>> a(m, vector<int> (n ,0));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }

    vector<int> prev(n, -1);    
    // base case
    prev[0] = 1; 
    for(int i=0;i<m;i++)
    {
        vector<int> cur(n, -1);
        for(int j=0;j<n;j++)
        {
            if(a[i][j] == (-1))
            {
                cur[j] = 0;
            }
            else if(i == 0 && j == 0)
            {
                prev[0] = 1;
            }
            else
            {
                int up = 0, left = 0;
                if(i > 0)
                {
                    up = prev[j];
                }
                if(j > 0)
                {
                    left = cur[j-1];
                }
                cur[j] = up + left;
            }
        }
        prev = cur;
    }
    cout << prev[n-1] << endl;

    return 0;
}