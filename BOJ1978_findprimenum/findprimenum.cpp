//https://www.acmicpc.net/problem/1978
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int num;
    int count = 0;
    bool isNotPrime;
    for (int i=0; i < n; i++)
    {
        cin >> num;
        if (num == 1)
            continue;

        isNotPrime = false;
        for (int j=2; j < num; j++)
        {
            isNotPrime = num % j == 0;
            if (isNotPrime)
                break;
        }
        count += !isNotPrime;
    }
    cout << count << '\n';
}