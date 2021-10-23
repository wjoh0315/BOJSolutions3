//https://www.acmicpc.net/problem/5622
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string in;
    cin >> in;

    int result = 0;
    for (int i=0; i < in.length(); i++)
    {
        if (in[i] <= 'O')
            result += 2 + ((in[i] - 'A' + 1) % 3 == 0 
                ? (in[i] - 'A' + 1) / 3 : (in[i] - 'A' + 1) / 3 + 1);
        else if (in[i] >= 'P' && in[i] <= 'S')
            result += 8;
        else if (in[i] >= 'T' && in[i] <= 'V')
            result += 9;
        else
            result += 10;
    }
    cout << result << '\n';
}