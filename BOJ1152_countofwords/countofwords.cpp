//https://www.acmicpc.net/problem/1152
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count = 0;
    string tmp;
    while (true)
    {
        cin >> tmp;
        if (cin.fail())
            break;
        count++;
    }
    cout << count << '\n';
}