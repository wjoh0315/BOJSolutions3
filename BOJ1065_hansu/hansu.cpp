//https://www.acmicpc.net/problem/1065
#include <iostream>
#include <string>
using namespace std;

int solve(int n)
{
    if (n < 100)
        return n;

    string tmp;
    int d = 0;
    int count = 99;
    bool success = true;
    for (int i=100; i < n+1; i++)
    {
        tmp = to_string(i);
        d = tmp[1] - '0' - (tmp[0] - '0');
        for (int j=2; j < tmp.length(); j++)
        {
            success = tmp[j] - '0' - (tmp[j-1] - '0') == d;
            if (!success)
                break;
        }
        if (success)
            count++;
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << solve(n) << '\n';
}