//https://www.acmicpc.net/problem/4948
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int process = 2;
    int count = 2;
    int result = 0;
    int noprime[246912] = { 1, };
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        for (int i=process; i < n+1; i++)
        {
            if (noprime[i - 1] == 1)
                continue;
            count = 2;
            while (i * count <= 246912)
            {
                noprime[i * count - 1] = 1;
                count++;
            }
        }
        process = n+1;

        result = 0;
        for (int i=n; i < 2*n; i++)
            result += noprime[i] == 0;
        cout << result << '\n';
    }
}