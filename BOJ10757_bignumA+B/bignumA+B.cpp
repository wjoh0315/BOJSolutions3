//https://www.acmicpc.net/problem/10757
#include <iostream>
#include <string>
using namespace std;

void maxmin(string a, string b, string *max, string *min)
{
    *max = a.length() >= b.length() ? a : b;
    *min = a.length() < b.length() ? a : b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a, b;
    string max, min;
    cin >> a >> b;
    
    int tmp = 0;
    int result = 0;
    int minidx = 0;
    int maxidx =0;
    maxmin(a, b, &max, &min);
    for (int i=0; i < max.length(); i++)
    {
        maxidx = max.length() - i - 1;
        minidx = min.length() - i - 1;
        if (minidx >= 0)
            result = max[maxidx] - '0' 
                + min[minidx] - '0' + tmp;
        else
            result = max[maxidx] - '0' + tmp;
        tmp = result / 10;
        max.replace(maxidx, 1, 
            to_string(result % 10));
    }
    if (tmp > 0)
        max = to_string(tmp) + max;
    cout << max << '\n';
}