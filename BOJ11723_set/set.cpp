//https://www.acmicpc.net/problem/11723
#include <iostream>
#include <bitset>
using namespace std;

int add(int bitmask, int x)
{
    return bitmask | (1 << x);
}

int remove(int bitmask, int x)
{
    return bitmask & ~(1 << x);
}

bool check(int bitmask, int x)
{
    return (bitmask & (1 << x)) == (1 << x);
}

int toggle(int bitmask, int x)
{
    return bitmask ^ (1 << x);
}

int all(int bitmask, int x)
{
    return bitmask | ~bitmask;
}

int empty(int bitmask, int x)
{
    return bitmask & ~bitmask;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> m;

    string cmd;
    int x;
    int bitmask = 0;
    for (int i=0; i < m; i++)
    {
        cin >> cmd;
        if (cmd == "add")
        {
            cin >> x;
            bitmask = add(bitmask, x);
        }
        else if (cmd == "remove")
        {
            cin >> x;
            bitmask = remove(bitmask, x);
        }
        else if (cmd == "check")
        {
            cin >> x;
            cout << check(bitmask, x) << '\n';
        }
        else if (cmd == "toggle")
        {
            cin >> x;
            bitmask = toggle(bitmask, x);
        }
        else if (cmd == "all")
        {
            bitmask = all(bitmask, x);
        }
        else if (cmd == "empty")
        {
            bitmask = empty(bitmask, x);
        }
        
    }
}