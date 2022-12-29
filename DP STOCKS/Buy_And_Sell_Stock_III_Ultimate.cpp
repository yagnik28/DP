#include <bits/stdc++.h>
using namespace std;

// Ultimate
// Using One Transaction Array
// T.C => O(N*4)
// S.C => O(5)

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i=0;i<n;i++)
    {
        cin >> prices[i];
    }

    vector<int> ahead(5, -1);
    vector<int> cur(5, -1);
    // here ahead and cur initialised with '0' so all the base cases for which we need to make '0' is already done '0'.

    // base case
    // (i) Transaction == 4
    for (int i = 0; i <= 4; i++)
    {
        ahead[i] = 0;
    }
    cur[4] = 0;

    // Transaction :
    // B S B S --> 0 1 2 3 => (Buy --> 0 & 2 => Even) , (Sell --> 1 & 3 => Odd)

    for (int i = n - 1; i >= 0; i--)
    {
        int profit;
        for (int transaction = 3; transaction >= 0; transaction--)
        {
            if (transaction % 2 == 0) // Buy Option
            {
                int buy = (-prices[i]) + ahead[transaction + 1];
                int not_buy = 0 + ahead[transaction];
                cur[transaction] = profit = max(buy, not_buy);
            }
            else // Sell Option
            {
                int sell = prices[i] + ahead[transaction + 1];
                int not_sell = 0 + ahead[transaction];
                cur[transaction] = profit = max(sell, not_sell);
            }
        }
        ahead = cur;
    }
    cout << ahead[0] << endl;

    return 0;
}