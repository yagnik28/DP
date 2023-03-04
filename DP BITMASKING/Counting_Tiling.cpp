#include<bits/stdc++.h>
using namespace std;

// SOLUION : https://www.youtube.com/watch?v=lPLhmuWMRag&list=PLb3g_Z8nEv1icFNrtZqByO1CrWVHLlO5g&index=9

/* QUESTION :
    CSES Question :
    Your task is to count the number of ways you can fill an n×m grid using 1×2 and 2×1 tiles.
    
    INPUT : 
    The only input line has two integers n and m.

    OUTPUT :
    Print one integer: the number of ways modulo 109+7 .

    Constraints :
    1≤n≤10
    1≤m≤1000
*/

const int M = 1e9 + 7;

void generate_next_masks(int i, int mask, int next_mask, vector<int> &next_masks, int n)
{
    // 'i' -> row for column 'j'.
    if(i == n)
    {
        next_masks.push_back(next_mask);
        return;
    }

    if(mask & (1 << i)) // current cell is blocked, so no blockage in next_maskas as we can't put any tile at cureent cell.
    {
        generate_next_masks(i + 1, mask, next_mask, next_masks, n); // no change in next mask.
    }
    if((i + 1) < n)
    {
        // current cell and below cell has no blockage so vertical tile can placed.
        // as vetical tile placed, no blockage in next_mask, so stays the same. 
        if((mask & (1 << i) == 0) && (mask & (1 << (i + 1)) == 0)) 
        {
            generate_next_masks(i + 2, mask, next_mask, next_masks, n);
        }
    }
    if(mask & (1 << i) == 0)
    {
        /* 
            -> we have taken case of 'i' & 'i+1' where both are not blocked for 'mask'.
            -> we have taken case of 'i' where it is blocked for 'mask'. 
            -> remaining case is this one only of 'i' where it is not blocked.
        */
        // as we have only option to put horizontal tile, next_mask will change for this row as '1'(blocked).
        generate_next_masks(i + 1, mask, next_mask + (1 << i), next_masks, n);
    }
}

int f(int j, int mask, vector<vector<int>> &dp, int n, int m)
{
    if(j == m)
    {
        if(mask == 0)
        {
            return 1;
        }
        return 0;
    }
    if(dp[j][mask] != -1)
    {
        return dp[j][mask];
    }

    int ans = 0;
    vector<int> next_masks;
    int next_mask = 0;
    generate_next_masks(0, mask, next_mask, next_masks, n); // (row, mask, next_mask, next_masks, n).

    for(int next_mask : next_masks)
    {
        ans = (ans + f(j + 1, next_mask, dp, n, m)) % M;
    }

    return dp[j][mask] = ans;

}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(1001, vector<int> ((1 << 11), -1)); 
    // dp(i, mask) => 'i'-> column, 'mask'->cell which is already filled.
    // dp(i, mask) -> number of possible ways to fill grid from 'i'th column to till 'm'th column with given filled cells.
    int mask = 0;
    cout << f(0, mask, dp, n, m) % M << endl;

    return 0;
}