//https://www.acmicpc.net/problem/1011
/*
풀이법 1 - 논리적 방법

k-1, k, k+1 광년을 더 이동할 수 있으며, 도착 직전에는 1 광년을 이동해야하니 
각 항은 1 증가 or 유지 or 1 감소하는 관계를 가지며, 따라서
9 -> 1 2 3 2 1, 18 -> 1 2 3 4 3 2 2 1 과 같이 증가 or 유지되다 감소하는 양상을 보임.
이와 같은 수열을 만들기 위한 논리는 다음과 같다고 할 수 있음.

1. 현재 위치에서 k+1 광년 더 갔을 때 적어도 그 이전만큼의 거리를 더 갈 수 있는가.
2. 그렇다면 이동하기 바로 이전의 거리만큼 더 가보자. 남는 거리가 있는가.
3. 남은 거리가 없다면 도착한 것이지만, 남은 거리가 있다면 도중 증가와 감소가 아닌 유지되는 관계를 보인 것이다.
따라서 1번의 k+1보다 남은 거리가 더 길다면 2번, 아니면 1번 더 갔다고 볼 수 있다.
(k+1보다 남은 거리가 더 길면서 1번만 더 간 경우는 없다. 그렇다면 이미 k+2로 채워졌을 것이기 때문,
k+1보다 남은 거리가 더 길다면 무조건 남은 거리 = a + b <= 2k+2, 1 <= a <= k+1, 1 <= b <= k+1가 성립하고,
k+1보다 남은 거리가 더 짧거나 같다면 b가 0, 남은 거리 = a이다.)
*/
#include <iostream>
using namespace std;

int solve(int x, int y)
{
    int dist = abs(x - y);
    int cur = 1;
    int sum = cur;
    int count = 1;
    while (true)
    {
        if (dist - sum - (cur + 1) >= sum)
        {
            sum += ++cur;
            count++;
        }
        else
        {
            sum += sum - cur;
            count += count - 1;
            break;
        }
    }
    count += dist - sum > 0 
        ? (dist - sum > cur ? 2 : 1) : 0;
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int x, y;
    for (int i=0; i < t; i++)
    {
        cin >> x >> y;
        cout << solve(x, y) << '\n';
    }
}