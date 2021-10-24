//https://www.acmicpc.net/problem/2775
#include <iostream>
using namespace std;

int solve(int k, int n)
{
    int **dp = new int*[k+1];
    for (int i=0; i < k+1; i++)
    {
        dp[i] = new int[n];
        for (int j=1; j < n+1; j++)
        {
            if (i == 0)
                dp[i][j-1] = j;
            else
                dp[i][j-1] = j == 1 ? 1 : dp[i][j-2] + dp[i-1][j-1];
        }
    }
    return dp[k][n-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int k, n;
    for (int i=0; i < t; i++)
    {
        cin >> k >> n;
        cout << solve(k, n) << '\n';
    }
}