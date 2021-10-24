//https://www.acmicpc.net/problem/2292
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // (n - 1)/6 = x(1+x)/2
    // 3x^2 + 3x - (n - 1) = 0
    // x = -3 + sqrt(3^2 + 12(n-1)) / 6 (if n % x(1+x)/2 == 0)
    // cout << ceil((-3 + sqrt(3 * 3 + 12 * (n - 1))) / 6) << '\n';
    int count = 1;
    int start = 1;
    int end = 6;
    while (true)
    {
        if (n == 1)
        {
            cout << 1 << '\n';
            break;
        }

        if (n - 1 >= start && n - 1 <= end)
        {
            cout << count+1 << '\n';
            break;
        }
        else
        {
            count++;
            start = end + 1;
            end += 6 * count;
        }
    }
}