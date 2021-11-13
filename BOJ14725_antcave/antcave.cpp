//https://www.acmicpc.net/problem/14725
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Trie
{
    private:
        string cur;
        vector<Trie> child;

    public:
        Trie(string s)
        {
            this->cur = s;
        }

        bool operator<(Trie t)
        {
            int comp = this->cur.compare(t.cur);
            return comp <= 0;
        }

        Trie* find(string f)
        {
            for (vector<Trie>::iterator iter=this->child.begin();
                iter != this->child.end(); iter++)
            {
                if (iter->cur == f)
                    return &(*iter);
            }
            return NULL;
        }

        void insert(vector<string> ins)
        {
            Trie *current = this;
            for (vector<string>::iterator iter=ins.begin();
                iter != ins.end(); iter++)
            {
                Trie *search = current->find(*iter);
                if (search == NULL)
                {
                    current->child.push_back(*(new Trie(*iter)));
                    search = &(current->child.back());
                }
                current = search;
            }
        }

        void sortTrie()
        {
            sort(this->child.begin(), this->child.end());
            for (vector<Trie>::iterator iter=this->child.begin();
                iter != this->child.end(); iter++)
            {
                iter->sortTrie();
            }
        }

        void print(int rfloor)
        {
            for (vector<Trie>::iterator iter=this->child.begin();
                iter != this->child.end(); iter++)
            {
                for (int i=0; i < rfloor; i++)
                    cout << "--";
                cout << iter->cur << '\n';
                iter->print(rfloor + 1);
            }
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int k;
    Trie t("");
    for (int i=0; i < n; i++)
    {
        cin >> k;
        string in;
        vector<string> ins;
        for (int j=0; j < k; j++)
        {
            cin >> in;
            ins.push_back(in);
        }
        t.insert(ins);
    }
    t.sortTrie();
    t.print(0);
}