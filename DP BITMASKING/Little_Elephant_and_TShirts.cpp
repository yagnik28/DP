#include<bits/stdc++.h>
using namespace std;

// SOLUTION : https://www.youtube.com/watch?v=Smem2tVQQXU&list=PLb3g_Z8nEv1icFNrtZqByO1CrWVHLlO5g&index=6

// QUESTION :
/*
    Little Elephant and his friends are going to a party. Each person has his own collection of T-Shirts. There are 100 different kind of T-Shirts. Each T-Shirt has a unique id between 1 and 100. No person has two T-Shirts of the same ID.

    They want to know how many arrangements are there in which no two persons wear same T-Shirt. One arrangement is considered different from another arrangement if there is at least one person wearing a different kind of T-Shirt in another arrangement.

    INPUT :
    First line of the input contains a single integer T denoting number of test cases. Then T test cases follow.

    For each test case, first line contains an integer N, denoting the total number of persons. Each of the next N lines contains at least 1 and at most 100 space separated distinct integers, denoting the ID's of the T-Shirts ith person has.

    OUTPUT :
    For each test case, print in single line the required number of ways modulo 1000000007 = 109+7.

    Constraints
    1 ≤ T ≤ 10
    1 ≤ N ≤ 10
*/

/* Approach 1 : Make a set of T-Shirts and represent it by a Mask of 100 bits for 100 T-Shirts.
                Now, assign T-Shirts to persons from P1 to PN if T-Shirt is available to Pi.
    T.C => O(10 * 100 * 2 ^ 100) => VERY LARGE.
*/

/* Approach 2 : Make a set of Persons and represent it by a Mask of N bits(N <= 10).
                Now, Assign a person to a particular T-Shirts if this T-Shirt is available to Pi.
    T.C => O(100 * 10 * 2^10) => 10^6.
*/

const int M = 1e9 + 7;

int f(int shirt, int mask, vector<vector<int>> &people, vector<vector<int>> &dp, int n)
{
    if(mask == (1 << n) - 1)
    {
        return 1;
    }
    if(shirt == 101)
    {
        return 0;
    }
    if(dp[shirt][mask] != -1)
    {
        return dp[shirt][mask];
    }

    int not_Assign = f(shirt + 1, mask, people, dp, n);
    int assign = 0;
    for(int j = 0; j < n; j++)
    {
        if(mask & (1 << j)) continue; // A T-Shirt is already assigned to this 'j' th person.
        if(people[j][shirt]) // 'j'th Person.
        {
            assign = (assign + f(shirt + 1, mask ^ (1 << j), people, dp, n)) % M;
        }
    }
    return dp[shirt][mask] = (assign + not_Assign) % M;
}

void in(int n, vector<vector<int>> &people)
{
    string s;
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
        getline(cin, s);
        stringstream in(s);
        int a;
        while(in>>a)
        {
            people[i][a] = 1;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> people(11, vector<int> (101, 0));
    in(n, people);

    vector<vector<int>> dp(101, vector<int> (1025, -1)); // dp(i, S) => i -> T-Shirts, S -> Persons Set.
    int mask = 0;
    int ans = f(0, mask, people, dp, n);
    cout << ans << endl;

    return 0;
}