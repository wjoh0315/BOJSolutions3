//https://www.acmicpc.net/problem/2170
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    pair<int, int> *lines = new pair<int, int>[n];
    for (int i=0; i < n; i++)
        cin >> lines[i].first >> lines[i].second;
    // 구간을 시작점이 작은 순으로 정렬
    sort(lines, lines + n);

    int length = 0;
    pair<int, int> range;
    range = lines[0];
    for (int i=1; i < n; i++)
    {
        // 두 구간의 교집합이 공집합이면 현재 구간의 길이를 저장해놓고 새 구간 정의
        if (lines[i].first > range.second || lines[i].second < range.first)
        {
            length += range.second - range.first;
            range = lines[i];
        }
        range.first = min(range.first, lines[i].first);
        range.second = max(range.second, lines[i].second);
    }
    length += range.second - range.first;
    cout << length << '\n';
}