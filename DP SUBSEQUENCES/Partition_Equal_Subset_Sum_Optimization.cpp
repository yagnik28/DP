#include<bits/stdc++.h>
using namespace std;

/*
    Recursion : 
    T.C => O(2^N)
    S.C => O(N)
*/

// Tabulation : 
// T.C => O(N*ReqSum)
// S.C => O(ReqSum)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int TotalSum = 0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        TotalSum += a[i];
    }

    int ReqSum = TotalSum / 2;
    if(TotalSum % 2 == 1)
    {
        cout << false << endl;
    }

    else
    {
        vector<int> prev(ReqSum + 1, 0);
        vector<int> cur(ReqSum + 1); 

        // BASE CASE
        prev[0] = cur[0] = 1;
        prev[a[0]] = 1; // at idex i = 0, ReqSum = a[0] and yes it is posible -> prev[a[0]] = 1.

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=ReqSum;j++)
            {
                bool not_take = prev[j];
                bool take = 0; // 0 = false
                if(j >= a[i])
                {
                    take = prev[j - a[i]];
                }
                cur[j] = (take | not_take);
            }
            prev = cur;
        }

        cout << prev[ReqSum] << endl;
    }

    return 0;
}