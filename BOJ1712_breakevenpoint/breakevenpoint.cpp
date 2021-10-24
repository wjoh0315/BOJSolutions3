//https://www.acmicpc.net/problem/1712
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    // bx + a = cx, x = -a / (b - c)
    if (b - c >= 0)
        cout << -1 << '\n';
    else 
        cout << -a / (b - c) + 1 << '\n';
}