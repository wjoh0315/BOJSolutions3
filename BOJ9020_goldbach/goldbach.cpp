//https://www.acmicpc.net/problem/9020
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int n;
    int process = 2;
    int count = 2;
    int result = 0;
    int noprime[10000] = { 1, };
    for (int i=0; i < t; i++)
    {
        cin >> n;
        if (n == 0)
            break;
        for (int j=process; j < n/2+1; j++)
        {
            if (noprime[j - 1] == 1)
                continue;
            count = 2;
            while (j * count <= 10000)
            {
                noprime[j * count - 1] = 1;
                count++;
            }
        }
        process = n/2+1;

        result = 0;
        for (int i=1; i < n/2+1; i++)
        {
            if (noprime[i-1] == 0
            && noprime[n-i-1] == 0)
                result = i;
        }
        cout << result << ' ' << n - result << '\n';
    }
}