#include <iostream>
#include <string>
using namespace std;

void d()
{
    string tmp;
    int computetmp = 0;
    int selfnums[10000] = { 0, };
    for (int i=1; i <= 10000; i++)
    {
        if (selfnums[i-1] == 0)
        {
            cout << i << '\n';
            tmp = to_string(i);
            while (true)
            {
                computetmp = 0;
                for (int j=0; j < tmp.length(); j++)
                    computetmp += tmp[j] - '0';
                tmp = to_string(stoi(tmp) + computetmp);
                if (stoi(tmp) <= 10000)
                    selfnums[stoi(tmp) - 1] = 1;
                else
                    break;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    d();
}