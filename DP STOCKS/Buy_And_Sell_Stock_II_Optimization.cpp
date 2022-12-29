#include <bits/stdc++.h>
using namespace std;

// Optimization 
// T.C => O(N*2)
// S.C => O(2) 

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

    // base case
    ahead[0] = ahead[1] = 0; // when whole array travesed after that nothing is in profit.

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
                int sell = prices[i] + ahead[1];
                int not_sell = 0 + ahead[0];
                cur[0] = profit = max(sell, not_sell);
            }
        }
        ahead = cur;
    }
    cout << ahead[1] << endl;

    return 0;
}