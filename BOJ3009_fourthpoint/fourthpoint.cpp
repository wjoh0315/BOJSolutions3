//https://www.acmicpc.net/problem/3009
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    int tmp1 = 0; 
    int tmp2 = 0;
    for (int i=0; i < 3; i++)
    {
        cin >> x >> y;
        tmp1 ^= x;
        tmp2 ^= y;
    }
    cout << tmp1 << ' ' << tmp2 << '\n';
}