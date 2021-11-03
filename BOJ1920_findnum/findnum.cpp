//https://www.acmicpc.net/problem/1920
#include <iostream>
#include <algorithm>
using namespace std;

bool binarysearch(int cur, int *sortedarr,
int begin, int end)
{
    if (begin > end)
        return false;

    int mid = (begin + end)/2;
    if (cur < sortedarr[mid])
        return binarysearch(cur, sortedarr, 
            begin, mid - 1);
    else if (cur > sortedarr[mid])
        return binarysearch(cur, sortedarr, 
            mid + 1, end);
    else // cur == sortedarr[mid]
        return true;
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
        cout << binarysearch(cur, arr, 0, n - 1) << '\n';
    }
}