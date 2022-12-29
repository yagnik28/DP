#include <bits/stdc++.h>
using namespace std;

// Optimization 
// T.C => O(N*2*3)
// S.C => O(2*3) 

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    vector<vector<int>> ahead(2, vector<int> (3,-1));

    // base case
    // for cap==0 then buy can be anything.
    for (int buy = 0; buy <= 1; buy++)
    {
        ahead[buy][0] = 0; // if(cap==0){return 0;}
    }
    for (int buy = 0; buy <= 1; buy++) // for ind==n then buy & cap can be anything.
    {
        for (int cap = 0; cap <= 2; cap++)
        {
            ahead[buy][cap] = 0; // if(n==0){return 0;}
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int profit;
        vector<vector<int>> cur(2, vector<int> (3, -1));
        for (int prev_buy = 0; prev_buy <= 1; prev_buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                if (prev_buy == 1)
                {
                    int buy = (-prices[i]) + ahead[0][cap];
                    int not_buy = 0 + ahead[1][cap];
                    cur[prev_buy][cap] = profit = max(buy, not_buy);
                }
                else
                {
                    int sell = prices[i] + ahead[1][cap - 1];
                    int not_sell = 0 + ahead[0][cap];
                    cur[prev_buy][cap] = profit = max(sell, not_sell);
                }
            }
        }
        ahead = cur;
    }
    cout << ahead[1][2] << endl;

    return 0;
}