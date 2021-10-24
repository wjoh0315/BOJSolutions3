//https://www.acmicpc.net/problem/2839
/* 
n은 두 소수 3과 5로 이루어진 자연수임.
따라서 모든 케이스의 n은 3으로만 or 5로만 or 3과 5로 이루어져 있다는 사실을 알 수 있음.
3으로만 이루어져있는 경우 n % 3으로 체크, 5로만 이루어져 있는 경우는 n % 5로 체크하면 되며,
3과 5로 이루어져있을시 3과 5는 각각의 쌍이 존재하므로 3 + 5 = 8, 
쌍을 제외한 나머지 값 즉, n - 8을 n % 3 또는 n % 5로 체크하면 됨
이와 같은 과정을 n이 3이 아니고 5보다 작을 때까지 반복해 가장 작은 값을 택하면 해결
*/
#include <iostream>
using namespace std;

int solve(int n)
{
    int count = 0;
    int min = -1;
    while (true)
    {
        if (n != 3 && n < 5)
            break;
        if (n % 5 == 0)
            min = min == -1 || count + n / 5 < min 
                ? count + n / 5 : min;
        else if (n % 8 == 0)
            min = min == -1 || count + n / 8 * 2 < min 
                ? count + n / 8 * 2 : min;
        else if (n % 3 == 0)
            min = min == -1 || count + n / 3 < min 
                ? count + n / 3 : min;
        n -= 8;
        count += 2;
    }
    return min;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    cout << solve(n) << '\n';
}