//https://www.acmicpc.net/problem/3273
#include <iostream>
#include <algorithm>
using namespace std;

int solve(int *arr, int n, int x)
{
    // 배열의 시작
    int a = 0;
    // 배열의 끝
    int b = n-1;
    // 횟수
    int count = 0;
    // 정렬
    sort(arr, arr + n);

    while (a < b)
    {
        /* a가 증가하면 arr[a]도 증가, 따라서 
        arr[a] + arr[b]가 x보다 작은 경우 a를 증가시킨다 */
        if (arr[a] + arr[b] < x)
            a++;
        /* b가 감소하면 arr[b]도 감소, 따라서
        arr[a] + arr[b]가 x보다 큰 경우 b를 감소시킨다 */
        else if (arr[a] + arr[b] > x)
            b--;
        // arr[a] + arr[b] == x
        else 
        {
            /* a 증가와 b 감소 -> 효율 up
            (한쪽만 증가 혹은 감소를 한다면 루프를 한번 더 돌아야하기 때문) */
            a++;
            b--;
            count++;
        }
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i=0; i < n; i++)
        cin >> arr[i];

    int x;
    cin >> x;

    cout << solve(arr, n, x) << '\n';
}