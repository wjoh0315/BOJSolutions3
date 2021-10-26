//https://www.acmicpc.net/problem/4153
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, z;
    while (true)
    {
        cin >> x >> y >> z;
        if (x + y + z == 0)
            break;
        if (x * x + y * y == z * z
        || y * y + z * z == x * x
        || x * x + z * z == y * y)
            cout << "right" << '\n';
        else
            cout << "wrong" << '\n';
    }
}