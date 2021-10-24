//https://www.acmicpc.net/problem/2869
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, v;
    cin >> a >> b >> v;

    //cout << (int)ceil((double)(v - b) / (a - b)) << '\n';
    cout << (int)ceil((double)(v - a) / (a - b)) + 1 << '\n';
}