#include<bits/stdc++.h>
using namespace std;

/*
    Recursion :
    T.C => >>O(2^N)
    S.C = >>O(N)
*/

// Optimization : 
// T.C => O(N*N)
// S.C => O(N) 

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    vector<int> prev(N+1, -1);

    // BASE CASE
    for(int n=0;n<=N;n++)
    {
        prev[n] = n*a[0];
    }

    for(int ind=1;ind<N;ind++)
    {
        for(int n=1;n<=N;n++)
        {
            int not_take = 0 + prev[n];
            int take = INT_MIN;
            int rodlegth = ind + 1;
            if(rodlegth <= n)
            {
                take = a[ind] + prev[n - rodlegth];
            }
            prev[n] = max(take, not_take);
        }
    }

    cout << prev[N] << endl;
    

    return 0;
}