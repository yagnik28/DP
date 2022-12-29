#include<bits/stdc++.h>
using namespace std;

// Same to Same as Max_Sum_Non_Adjacent_Array.

// Solution :: 1st and last are also adjacent to each other 
//              so we can't take it in our some.

//Approch :: Find some of all as Max_Sum.... except last 
//           and Find some of all as Max_Sum.... except 1st. 

// Tabulation.
// T.C ==> O(N), S.C ==> O(N).

int Max_Money(vector<int> &b)
{
    int n = b.size();
    int prev = b[0]; // prev = dp[0].
    int prev2 = 0;
    for(int i=1;i<n;i++)
    {
        int pick = b[i];
        if(i - 2 >= 0)
        {
            pick += prev2; // prev2 = dp[i - 2].
        }
        int not_pick = 0 + prev; // prev = dp[i - 1].
        
        int cur = max(pick, not_pick); // cur = dp[i].
        prev2 = prev;
        prev = cur;
    }
    return prev;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    if(n == 1)
    {
        cout << a[0] << endl;
    }
    else
    {
        vector<int> temp1, temp2;
        for(int i=0;i<n;i++)
        {
            if(i != 0)
            {
                temp1.push_back(a[i]);
            }
            if(i != n - 1)
            {
                temp2.push_back(a[i]);
            }
        }
        cout << max(Max_Money(temp1), Max_Money(temp2)) << endl;
    }

    return 0;
}