//https://www.acmicpc.net/problem/1786
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> pi_get(string p)
{
    vector<int> pi(p.length(), 0);
    int begin = 0;
    for (int i=1; i < p.length(); i++)
    {
        while (begin > 0 && p[begin] != p[i])
            begin = pi[begin-1];
        if (p[begin] == p[i])
            pi[i] = ++begin;
    }
    return pi;
}

void kmp(string t, string p)
{
    vector<int> pos;
    vector<int> pi = pi_get(p);
    int begin = 0;
    for (int i=0; i < t.length(); i++)
    {
        while (begin > 0 && t[i] != p[begin])
            begin = pi[begin-1];
        if (t[i] == p[begin])
        {
            if (begin == p.length() - 1)
            {
                pos.push_back(i - begin + 1);
                begin = pi[begin];
            }
            else begin++;
        }
    }

    cout << pos.size() << '\n';
    for (vector<int>::iterator iter=pos.begin(); 
        iter != pos.end(); iter++)
    {
        cout << *iter << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string t, p;
    getline(cin, t, '\n');
    getline(cin, p, '\n');

    kmp(t, p);
}