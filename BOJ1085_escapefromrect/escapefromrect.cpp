//https://www.acmicpc.net/problem/1085
#include <iostream>
#define MIN(X,Y) (X<Y?X:Y)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, w, h;
    cin >> x >> y >> w >> h;

    cout << (MIN(x, MIN(y, MIN(w-x, h-y)))) << '\n';
}