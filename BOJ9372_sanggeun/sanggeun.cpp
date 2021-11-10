//https://www.acmicpc.net/problem/9372
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    int n, m, tmp;
    for (int i=0; i < t; i++)
    {
        cin >> n >> m;
        for (int j=0; j < m; j++)
            cin >> tmp >> tmp;
        cout << n - 1 << '\n';
    }
}