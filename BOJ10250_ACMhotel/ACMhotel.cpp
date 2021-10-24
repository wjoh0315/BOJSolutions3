//https://www.acmicpc.net/problem/10250
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int h, w, n;
    for (int i=0; i < t; i++)
    {
        cin >> h >> w >> n;
        cout << (n - 1) % h + 1 
            << ((n % h == 0 ? n / h - 1 : n / h) + 1 < 10 ? "0" : "")
            << ((n % h == 0 ? n / h - 1 : n / h) + 1) << '\n';
    }
}