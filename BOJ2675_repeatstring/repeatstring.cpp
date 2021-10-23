//https://www.acmicpc.net/problem/2675
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int r;
    string s;
    for (int i=0; i < t; i++)
    {
        cin >> r;
        cin >> s;
        for (int j=0; j < s.length(); j++)
        {
            for (int k=0; k < r; k++)
                cout << s[j];
        }
        cout << '\n';
    }
}