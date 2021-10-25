//https://www.acmicpc.net/problem/2581
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    int min = -1;
    int sum = 0;
    bool isNotPrime;
    for (int num=m; num < n+1; num++)
    {
        if (num == 1)
            continue;

        isNotPrime = false;
        for (int j=2; j < num; j++)
        {
            isNotPrime = num % j == 0;
            if (isNotPrime)
                break;
        }
        if (min == -1 && !isNotPrime)
            min = num;
        sum += !isNotPrime ? num : 0;
    }
    if (min == -1 && sum == 0)
        cout << -1 << '\n';
    else
    {
        cout << sum << '\n';
        cout << min << '\n';
    }
}