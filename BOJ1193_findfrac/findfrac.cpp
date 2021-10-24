//https://www.acmicpc.net/problem/1193
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    cin >> x;

    int count = 1;
    bool reverse = true;
    while (x > count)
    {
        x -= count++;
        reverse = !reverse;
    }
    cout << (reverse ? (count + 1) - x : x) << '/' 
        << (reverse ? x: (count + 1) - x) << '\n';
}