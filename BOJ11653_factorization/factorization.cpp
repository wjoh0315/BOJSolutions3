//https://www.acmicpc.net/problem/11653
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int tmp = ceil(sqrt(n) + 1) + 1;
    for (int i=2; i < tmp; i++)
    {
        while (n % i == 0)
        {
            cout << i <<'\n';
            n = n / i;
        }
    }
    if (n > 1)
        cout << n << '\n';
}