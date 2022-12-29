#include<bits/stdc++.h>
using namespace std;

/*
    Recusrion : 
    T.C => O((3^N)*(3^N))
    S.C => O(N)
*/

// Optimization : 
// T.C => O(N*M*M*9)
// S.C => O(M*M) (3D SPACE -> 2D SPACE)

const int MINIMUM = -1e8;

/*
    f(i1, j1) -> Alice, f(i2, j2) -> Bob => Alice and Bob will run together,
    means both will be on same row everytime so i1 = i1, -> i1 = i2 = i.
    4D DP -> 3D DP conversion
*/


int main()
{
    int n, m;
    cin >> n >> m; // n -> rows, m -> coumns.
    vector<vector<int>> a(n, vector<int> (m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> next(m, vector<int> (m));

    // BASE CASE
    for(int j1 = 0; j1 < m; j1++)
    {
        for(int j2 = 0; j2 < m; j2++)
        {
            if(j1 == j2)
            {
                next[j1][j2] = a[n-1][j1];
            }
            else
            {
                next[j1][j2] = a[n-1][j1] + a[n-1][j2];
            }
        }
    }

    
    for(int i=n-2;i>=0;i--)
    {
        vector<vector<int>> cur(m, vector<int> (m));
        for(int j1 = 0; j1 < m; j1++)
        {
            for(int j2 = 0; j2 < m; j2++)
            {
                // for all 9 combo paths of Alice and Bob,
                // instead of running fuction individually and take maximum, 
                // we run 2 for loops because of 9 paths.
                int mx = MINIMUM;
                for(int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for(int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int value = 0;
                        if(j1 == j2)
                        {
                            value = a[i][j1];
                        }
                        else
                        {
                            value = a[i][j1] + a[i][j2]; 
                        }

                        if((j1+dj1) >= 0 && (j1+dj1) < m && (j2+dj2) >= 0 && (j2+dj2) < m )
                        {
                            value += next[j1+dj1][j2+dj2];
                        }
                        else
                        {
                            value += MINIMUM;
                        }
                        mx = max(mx, value);
                    }
                }
                cur[j1][j2] = mx;
            }
        }
        next = cur;
    }

    cout << next[0][m-1] << endl;

    return 0;
}

/*
    TESTCASE : 
        3 4
        2 3 1 2
        3 4 2 2 
        5 6 3 5
    ANS : 
        21
*/