//https://www.acmicpc.net/problem/1002
#include <iostream>
#include <cmath>
#define MAX(X,Y) (X>Y?X:Y)
#define MIN(X,Y) (X<Y?X:Y)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    int x1, y1, r1, x2, y2, r2;
    for (int i=0; i < n; i++)
    {
        cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;

        double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        
        // 두 원이 만나지 않는 경우 (교점 없음)
        if (dist > r1 + r2 || dist < MAX(r1, r2) - MIN(r1, r2))
            cout << 0 << '\n';
        // 두 원이 한 점에서 만나는 경우 (교점이 1개)
        else if (dist != 0 && (dist == r1 + r2 || dist == MAX(r1, r2) - MIN(r1, r2)))
            cout << 1 << '\n';
        // 두 원의 일부가 서로 겹쳐 두 점에서 만나는 경우 (교점이 2개)
        else if (dist != 0 && (dist < r1 + r2 || dist > MAX(r1, r2) - MIN(r1, r2)))
            cout << 2 << '\n';
        // 두 원이 완전히 겹치는 경우 (교점이 무수히 많음, 교점의 개수가 무한대)
        else
            cout << -1 << '\n';
    }
}