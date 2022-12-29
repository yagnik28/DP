#include <bits/stdc++.h>
using namespace std;

// T.C => O(N*(M+N))
// S.C => O(N)

// function to find maximum area of rectangle from histogram.
int largestRectangleArea(vector<int> &histo)
{
    stack<int> st;
    int maxA = 0;
    int n = histo.size();
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i]))
        {
            int height = histo[st.top()];
            st.pop();
            int width;
            if (st.empty())
            {
                width = i;
            }
            else
            {
                width = i - st.top() - 1;
            }
            maxA = max(maxA, width * height);
        }
        st.push(i);
    }
    return maxA;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    // we are sending every row one by one and checking area of rectangle 
    // like, 1st -> 1-row, 2nd -> 1,2-row, 3rd -> 1,2,3-row, like this...
    vector<int> height(m, 0);
    int mx_area = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
            {
                height[j]++;
            }
            else
            {
                height[j] = 0;
            }
        }
        int area = largestRectangleArea(height);
        mx_area = max(mx_area, area);
    }
    cout << mx_area << endl;

    return 0;
}