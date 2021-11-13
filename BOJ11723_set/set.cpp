//https://www.acmicpc.net/problem/11723
#include <iostream>
#include <bitset>
using namespace std;

int add(int bitmask, int x)
{
    // 000...1...0 (x번째 비트)와 OR 연산
    return bitmask | (1 << x);
}

int remove(int bitmask, int x)
{
    // 111...0...1 (x번째 비트, NOT)와 AND 연산
    return bitmask & ~(1 << x);
}

bool check(int bitmask, int x)
{
    // 000...1...0 (x번째 비트)와 AND 연산을 하여 비교
    return (bitmask & (1 << x)) == (1 << x);
}

int toggle(int bitmask, int x)
{
    // 000...1...0 (x번째 비트)와 XOR 연산
    return bitmask ^ (1 << x);
}

int all(int bitmask, int x)
{
    // 비트마스크의 NOT과 OR 연산
    return bitmask | ~bitmask;
}

int empty(int bitmask, int x)
{
    // 비트마스크의 NOT과 AND 연산
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