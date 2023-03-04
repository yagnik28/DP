#include<bits/stdc++.h>
using namespace std;

// Soution : https://www.youtube.com/watch?v=d7kvyp6dfz8&list=PLb3g_Z8nEv1icFNrtZqByO1CrWVHLlO5g&index=5

/*
    Codeforces Beta Round 16 (Div. 2 Only)
    E. Fish
*/

/* n fish, numbered from 1 to n, live in a lake. Every day right one pair of fish meet, and the probability of each 
   other pair meeting is the same. If two fish with indexes i and j meet, the first will eat up the second with the 
   probability aij, and the second will eat up the first with the probability aji = 1 - aij. The described process 
   goes on until there are at least two fish in the lake. For each fish find out the probability that it will survive to be the last in the lake.
*/

/* Input :
    The first line contains integer n (1 ≤ n ≤ 18) — the amount of fish in the lake. Then there follow n lines with
    n real numbers each — matrix a. aij (0 ≤ aij ≤ 1) — the probability that fish with index i eats up fish with 
    index j. It's guaranteed that the main diagonal contains zeros only, and for other elements the following is 
    true: aij = 1 - aji. All real numbers are given with not more than 6 characters after the decimal point.
*/

/* Output :
    Output n space-separated real numbers accurate to not less than 6 decimal places. Number with index i should be
    equal to the probability that fish with index i will survive to be the last in the lake.

*/

double probMoveState(int prev_mask, int j, vector<vector<double>> &p) 
// j -> fish that need to die at prev_state so we get cur_state.
{
    int n = p.size();
    int k = __builtin_popcount(prev_mask); // fishes alive.
    long long den = (k * (k - 1)) / 2;

    double moveProbability = 0;
    for(int fish = 0; fish < n; fish++)
    {
        if(prev_mask & (1 << fish)) // add only those who are present at prev_state.
        {
            moveProbability += p[fish][j];
        }
    }
    return moveProbability / (1.0 * den);
}

double f(int mask, vector<vector<double>> &p, vector<double> &dp)
{
    int n = p.size();
    int fishes_alive = __builtin_popcount(mask);

    if(fishes_alive == n)
    {
        return 1;
    }

    if(dp[mask] > -0.9) // because equal comparison of double & integer(-1) cause confusion.
    {
        return dp[mask];
    }

    // checking that which fishes are alive at previous state, trying all fishes.
    double ans = 0;
    for(int fish = 0; fish < n; fish++)
    {
        // currently not alive fishes we take and assuming it is alive at previous state.
        if(!(mask & (1 << fish)))
        {
            int prev_mask = mask ^ (1 << fish);

            double prev_state = f(prev_mask, p, dp); // it was '0' in mask, now done '1' means that fish added to set, as we are now going at prev_state throufh f() function.

            // probability of moving from prev_state to current_state by dieing fish = j.
            ans += probMoveState(prev_mask, fish, p) * prev_state;
        }
    }

    return dp[mask] = ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<double>> p(n, vector<double> (n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> p[i][j];
        }
    }

    vector<double> dp((1 << 19), -1);

    for(int i = 0; i < n; i++)
    {
        double ans = f((1 << i), p, dp); // (1 << i) means 'i'th Fish alive in lake at last.
        cout << fixed << setprecision(10) << ans << " ";
    }
    cout << endl;

    return 0;
}

// SOLUTION : 
/*

    SOLUTION For winning fish = 1, simillarly for 2, 3, .. n also possible. 

                {1, 2} 
                {1, 3}
        {1}
                .
                .
                .
                {1, k}
        => For fish = 1, wins from {1, 2, ...., n} is the case.
        Now, Say {1} is stay till last, so at previous state there will be {1, 2} OR {1, 3} OR {1, 4} ..... {1, k}
        k -> total fishes remains till state second last.

        simillarly, Go from bottom to top and base case will be when in 'set' all the fishes are present at that time probability will be '1', to fight fishes and go to next state 
        that is {1, 3, ... ,n} OR {1, 2, 4, .... , n} OR {1, 2, 3, .... , n - 1} 
        from starting state  {1, 2, 3, ....., n}.


                'j' -> fish that will gonna die at from state {S1} -> {S}. 
                '(1 / nC2) -> chance of selecting pair (1, j).
                {S1} -> probability = (1 / nC2) * [p1j + p2j + p3j + .... + pnj] (n = number of elements in set "S1")
                {S2}
        {S}
                .
                .
                .
                {Sn}

        nC2 => for selecting ant 2 fishes
        probability of fighting fish = 1 & 2 and fish = 1 wins => (1 / nC2) * p12
        For every fishes in set 'S1', it is (1/ nC2) * (p12 + p13 + ... + p1n).
        
        Finally, 

                {1, 2} -> from here to win fish = 1=> p12 * dp({1, 2}).
        {1}
                .
                .
                .
                {1, k}
        


*/
