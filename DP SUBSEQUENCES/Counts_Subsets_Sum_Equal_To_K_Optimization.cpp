#include<bits/stdc++.h>
using namespace std;

/*
    Recursion : 
    T.C => O(2^N)
    S.C => O(N)
*/

// Tabulation : 
// T.C => O(N*K)
// S.C => O(K)

int main()
{
    int n, K;
    cin >> n >> K;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    vector<int> prev(K + 1, 0);
    vector<int> cur(K + 1); 

    // BASE CASE
    if(a[0] == 0)
    {
        prev[0] = 2;
    }
    else
    {
        prev[0] = 1;
    }
    if(a[0] != 0 && a[0] <= K)
    {
        prev[a[0]] = 1; 
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=K;j++)
        {
            int not_take = prev[j];
            int take = 0; // 0 = false
            if(j >= a[i])
            {
                take = prev[j - a[i]];
            }
            cur[j] = (take + not_take);
        }
        prev = cur;
    }

    cout << prev[K] << endl;

    return 0;
}