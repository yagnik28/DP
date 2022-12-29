#include <bits/stdc++.h>
using namespace std;

// Tabulation
// T.C => O(N*2*k)
// S.C => O(2*k)

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    vector<int> ahead(2 * k + 1, -1);
    vector<int> cur(2 * k + 1, -1);

    // base case
    // (i) ind = n => transNo can be anything. in Optimisation ind is not there so for every element of 1D array ahead will have 0 at present.
    for (int transNo = 0; transNo <= 2 * k; transNo++)
    {
        ahead[transNo] = 0;
    }
    // (ii) transNo = 2*k => ind can be anything. in Optimization cur itself as present index so at present make 2*k 0 for ahead.
    cur[2 * k] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int profit;
        for (int transNo = 2 * k - 1; transNo >= 0; transNo--)
        {
            if (transNo % 2 == 0) // Buy Option
            {
                int buy = (-prices[i]) + ahead[transNo + 1];
                int not_buy = 0 + ahead[transNo];
                cur[transNo] = profit = max(buy, not_buy);
            }
            else
            {
                int sell = prices[i] + ahead[transNo + 1];
                int not_sell = 0 + ahead[transNo];
                cur[transNo] = profit = max(sell, not_sell);
            }
        }
        ahead = cur;
    }
    cout << ahead[0] << endl;

    return 0;
}