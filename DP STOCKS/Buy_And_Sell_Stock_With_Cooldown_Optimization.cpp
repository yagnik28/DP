#include <bits/stdc++.h>
using namespace std;

// Optimization 
// T.C => O(N*2)
// S.C => O(2*2) 

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    vector<int> ahead(2, -1);
    vector<int> ahead_2(2, -1);

    // base case
    // when whole array travesed after that nothing is in profit.
    ahead[0] = ahead[1] = 0; 
    ahead_2[0] = ahead_2[1] = 0; // for added condition of cooldown in which we sell at 'i' then we can't buy at 'i+1' so we direclty jump to 'i+2'.
    // For 'n-1' we will jump at 'n+1' which is ahead_2 for cur at sell condition.

    for (int i = n - 1; i >= 0; i--)
    {
        int profit;
        vector<int> cur(2, -1);
        for (int prev_buy = 0; prev_buy <= 1; prev_buy++)
        {
            if (prev_buy == 1)
            {
                int buy = (-prices[i]) + ahead[0];
                int not_buy = 0 + ahead[1];
                cur[1] = profit = max(buy, not_buy);
            }
            else
            {
                int sell = prices[i] + ahead_2[1];
                int not_sell = 0 + ahead[0];
                cur[0] = profit = max(sell, not_sell);
            }
        }
        ahead_2 = ahead;
        ahead = cur;
    }
    cout << ahead[1] << endl;

    return 0;
}