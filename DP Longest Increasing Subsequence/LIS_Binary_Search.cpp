#include<bits/stdc++.h>
using namespace std;

// Efficent Algorithm

// Binary Search(Lower_Bound)
// T.C => O(N*log(N))
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
    vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i] > temp.back())
            {
                temp.push_back(nums[i]);
            }
            else
            {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                // re-writing the array temp and at last whatever the size of temp is
                // length of LIS.
                temp[ind] = nums[i]; 
            }
        }
        cout << temp.size() << endl;

    return 0;
}