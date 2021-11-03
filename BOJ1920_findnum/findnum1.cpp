//https://www.acmicpc.net/problem/1920
#include <iostream>
#include <algorithm>
using namespace std;

bool binarysearch(int cur, int *sortedarr, int len)
{
    int mid;
    int begin = 0;
    int end = len - 1;
    while (begin <= end)
    {
        mid = (begin + end)/2;
        if (cur < sortedarr[mid])
            end = mid - 1;
        else if (cur > sortedarr[mid])
            begin = mid + 1;
        else
            return true;
    }
    return false;
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
    
    sort(arr, arr+n);

    int m;
    cin >> m;
    
    int cur;
    for (int i=0; i < m; i++)
    {
        cin >> cur;
        cout << binarysearch(cur, arr, n) << '\n';
    }
}