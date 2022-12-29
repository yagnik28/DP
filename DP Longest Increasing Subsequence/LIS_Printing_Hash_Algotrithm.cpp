#include<bits/stdc++.h>
using namespace std;

// Hash Algorithm
// T.C => O(N*N)
// S.C => O(N)

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> dp(n, 1); // every element has 1-length LIS which is that element itself.
    vector<int> hash(n);

    int mx = 0, lastIndex = 0; 
    for(int i=0;i<=n-1;i++)
    {
        hash[i] = i; // every index will store intially index of itself.
        for(int prev=0;prev<=i-1;prev++)
        {
            if(nums[i] > nums[prev])
            {
                if((1 + dp[prev]) > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev; // at hash's index 'i'(hash[i]) will be changed to prev from 'i'
                    // (hash[i] = prev -> YES) (hash[i] = i -> NO)
                    // which is the index(prev) with which the dp[i](LIS till index 'i') is increased.
                }
            }
        }
        if(dp[i] > mx)
        {
            mx = dp[i];
            lastIndex = i; // index from which LIS counting will start.
        }
    }

    vector<int> temp;
    temp.push_back(nums[lastIndex]);

    while(hash[lastIndex] != lastIndex) // means till lastIndex bacomes 0.
    {
        lastIndex = hash[lastIndex];
        temp.push_back(nums[lastIndex]);
    }

    reverse(temp.begin(), temp.end());

    cout << mx << endl; // Length of LIS

    // Printing LIS

    for(auto it : temp)
    {
        cout << it << " "; 
    }
    cout << endl;

    return 0;
}