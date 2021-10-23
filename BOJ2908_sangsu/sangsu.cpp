//https://www.acmicpc.net/problem/2908
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ra, rb;
    string a, b;
    cin >> a >> b;

    ra = (a[2] - '0') * 100 + (a[1] - '0') * 10
        + (a[0] - '0');
    rb = (b[2] - '0') * 100 + (b[1] - '0') * 10
        + (b[0] - '0');
    cout << (ra > rb ? ra : rb) << '\n';
}