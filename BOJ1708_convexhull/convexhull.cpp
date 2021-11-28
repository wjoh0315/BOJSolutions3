//https://www.acmicpc.net/problem/1708
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct point
{
    long long int x, y;
};
vector<point> points;

long long int ccw(const point &p1, const point &p2, const point &p3)
{
    // 두 벡터 p1p2, p1p3에 대해
    // 외적으로 좌회전, 우회전, 직진 판별 (좌회전이면 ccw > 0, 우회전이면 ccw < 0, 직진이면 ccw == 0)
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

long long int dist_s(const point &p1, const point &p2)
{
    long long int dx = p1.x - p2.x;
    long long int dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}

bool comp1(const point &p1, const point &p2)
{
    return p1.y == p2.y ? p1.x < p2.x : p1.y < p2.y;
}

bool comp2(const point &p1, const point &p2)
{
    // 반시계 방향
    return ccw(points.front(), p1, p2) > 0 
        || (ccw(points.front(), p1, p2) == 0 
            && dist_s(points.front(), p1) < dist_s(points.front(), p2));
}

vector<point> get()
{
    sort(points.begin(), points.end(), comp1);
    sort(points.begin() + 1, points.end(), comp2);

    vector<point> chpts;
    for (point p : points)
    {
        // 우회전인 경우
        while (chpts.size() >= 2 
            && ccw(chpts[chpts.size() - 2], chpts[chpts.size() - 1], p) <= 0)
        {
            chpts.pop_back();
        }
        chpts.push_back(p);
    }
    return chpts;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    point p;
    for (int i=0; i < n; i++)
    {
        cin >> p.x >> p.y;
        points.push_back(p);
    }

    cout << get().size() << '\n';
}