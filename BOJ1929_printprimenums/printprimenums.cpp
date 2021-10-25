//https://www.acmicpc.net/problem/1929
#include <iostream>
using namespace std;

void solve(int m, int n)
{
    int count = 2;
    int *noprime = new int[n] { 1, };
    for (int i=2; i < n / 2 + 1; i++)
    {
        while (i * count <= n)
        {
            noprime[i * count - 1] = 1;
            count++;
        }
        count = 2;
    }
    for (int i=m-1; i < n; i++)
    {
        if (noprime[i] != 1)
            cout << i + 1 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m, n;
    cin >> m >> n; 

    solve(m, n);
}