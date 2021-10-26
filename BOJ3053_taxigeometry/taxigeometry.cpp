//https://www.acmicpc.net/problem/3053
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r;
    cin >> r;

    cout << fixed;
    cout.precision(6);
    // 유클리드 기하학 (비선형적, 원) PIr^2
    cout << r * r * M_PI << '\n';
    // 택시 기하학 (선형적, 마름모, 정사각형) 2r^2
    cout << r * r * 2 << '\n';
}