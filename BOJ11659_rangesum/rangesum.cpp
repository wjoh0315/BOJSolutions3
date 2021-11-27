//https://www.acmicpc.net/problem/11659
#include <iostream>
using namespace std;

void solve(int n, int m)
{
    // 동적 계획법으로 각 인덱스까지의 합 메모이제이션
    int *dp = new int[n] { 0, };
    for (int i=0; i < n; i++)
    {
        cin >> dp[i];
        dp[i] += i > 0 ? dp[i-1] : 0;
    }

    int begin, end;
    for (int i=0; i < m; i++)
    {
        cin >> begin >> end;
        begin--; end--;
        cout << dp[end] - (begin > 0 ? dp[begin-1] : 0) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    solve(n, m);
}