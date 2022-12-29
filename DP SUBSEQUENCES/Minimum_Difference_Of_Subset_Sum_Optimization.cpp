#include<bits/stdc++.h>
using namespace std;

/*
    Recursion : 
    T.C => O(2^N)
    S.C => O(N)
*/

// Tabulation : 
// T.C => O(N*target)
// S.C => O(target)

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

    int target = TotalSum;

    vector<int> prev(target + 1, 0);
    vector<int> cur(target + 1); 

    // BASE CASE
    prev[0] = cur[0] = 1;
    prev[a[0]] = 1; // at idex i = 0, target = a[0] and yes it is posible -> prev[a[0]] = 1.

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=target;j++)
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

    int mn = 1e9;
    for(int i=0;i<=(TotalSum/2);i++)
    {
        if(prev[i] == 1)
        {
            int s1 = i;
            int s2 = TotalSum - i;
            mn = min(mn, abs(s2 - s1));
        }
    }

    cout << mn << endl;

    
    return 0;
}