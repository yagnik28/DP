#include<bits/stdc++.h>
using namespace std;

/*
    WHY DP HERE ?
    ANS :  DP is rembering the past and here also we remembering th 'mn'.
*/

// T.C => O(N)
// S.C => O(N)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int mn = a[0], maxprofit = 0;
    for(int i=1;i<n;i++)
    {
        int profit = a[i] - mn;
        maxprofit = max(maxprofit, profit);
        mn = min(mn, a[i]);
    }
    cout << maxprofit << endl;

    return 0;
}