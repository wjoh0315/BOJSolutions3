//https://www.acmicpc.net/problem/11720
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    char *nums = new char[n];
    cin >> nums;

    int sum = 0;
    for (int i=0; i < n; i++)
        sum += nums[i] - '0';
    cout << sum << '\n';
}