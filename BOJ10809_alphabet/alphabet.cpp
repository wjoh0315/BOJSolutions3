//https://www.acmicpc.net/problem/10809
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string in;
    cin >> in;

    size_t pos;
    for (int i=97; i <= 122; i++)
    {
        pos = in.find((char)i);
        if (pos != string::npos)
            cout << pos << ' ';
        else 
            cout << -1 << ' ';
    }
    cout << '\n';
}