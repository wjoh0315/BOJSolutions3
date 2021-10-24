//https://www.acmicpc.net/problem/2941
#include <iostream>
using namespace std;

int solve(string cur)
{
    string croatian[8] = {
        "c=", "c-", "dz=", "d-",
        "lj", "nj", "s=", "z="
    };

    int pos;
    int count = 0;
    bool isExist = true;
    while (isExist)
    {
        isExist = false;
        for (int i=0; i < 8; i++)
        {
            pos = cur.find(croatian[i]);
            if (pos != string::npos)
            {
                cur.replace(pos, croatian[i].length(), "_");
                isExist = true;
                count++;
                break;
            }
        }
    }
    for (int i=0; i < cur.length(); i++)
        count += cur[i] == '_' ? 0 : 1;
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string in;
    cin >> in;

    cout << solve(in) << '\n';
}