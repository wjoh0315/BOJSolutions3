//https://www.acmicpc.net/problem/1157
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string in;
    cin >> in;

    int max = 0;
    int maxidx = 0;
    int idx = 0;
    bool isSame = false;
    int alphabet[26] = { 0, };
    for (int i=0; i < in.length(); i++)
    {
        idx = in[i] > 'Z' ? in[i] - 'a' : in[i] - 'A';
        alphabet[idx]++;
        max = alphabet[idx] > max ? alphabet[idx] : max;
        maxidx = max == alphabet[idx] ? idx : maxidx;
    }
    for (int i=0; i < 26; i++)
    {
        if (i == maxidx)
            continue;
        isSame = max == alphabet[i];
        if (isSame)
            break;
    }
    if (isSame)
        cout << '?' << '\n';
    else 
        cout << (char)(maxidx + 'A') << '\n';
}