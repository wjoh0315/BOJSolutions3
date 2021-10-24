//https://www.acmicpc.net/problem/1316
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string in;
    int count = 0;
    for (int i=0; i < n; i++)
    {
        cin >> in;

        bool isGroupword = true;
        bool alphabet[26] = { false, };
        for (int j=0; j < in.length(); j++)
        {
            if (j == 0)
            {
                alphabet[in[j] - 'a'] = true;
                continue;
            }
            isGroupword = !(alphabet[in[j] - 'a'] 
                && in[j] != in[j-1]);
            if (!isGroupword)
                break;
            alphabet[in[j] - 'a'] = true;
        }
        count += isGroupword;
    }
    cout << count << '\n';
}