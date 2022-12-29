#include <bits/stdc++.h>
using namespace std;

// Ultimate 
// T.C => O(N*2)
// S.C => O(1) 

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    // base case
    int ahead_not_buy = 0; // ahead[0] = 0;
    int ahead_buy = 0; // ahead[1] = 0; when whole array travesed after that nothing is in profit.

    int cur_buy, cur_not_buy; // cur[1] & cur[0] respectively.

    for (int i = n - 1; i >= 0; i--)
    {
        int profit;

        int buy = (-prices[i]) + ahead_not_buy;
        int not_buy = 0 + ahead_buy;
        cur_buy = profit = max(buy, not_buy);

        int sell = prices[i] + ahead_buy;
        int not_sell = 0 + ahead_not_buy;
        cur_not_buy = profit = max(sell, not_sell);

        // ahead = cur --> ahead[1] = cur[1] & ahead[0] = ahead[0]
        ahead_buy = cur_buy;
        ahead_not_buy = cur_not_buy;
    }
    cout << ahead_buy << endl; // ahead[1]

    return 0;
}