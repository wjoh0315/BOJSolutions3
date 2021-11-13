//https://www.acmicpc.net/problem/2252
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class graph
{
    private:
        vector<int> *nodes;
        int *enter;
        int size;
        
    public:
        graph(int n)
        {
            nodes = new vector<int>[n];
            enter = new int[n] { 0, };
            size = n;
        }

        void edge(int v1, int v2)
        {
            nodes[v1].push_back(v2);
            enter[v2] += 1;
        }

        vector<int> topologicalSortPrint()
        {
            queue<int> q;
            for (int i=0; i < size; i++)
            {
                if (enter[i] == 0)
                    q.push(i);
            }
            for (int i=0; i < size; i++)
            {
                cout << q.front() + 1 << ' ';
                for (vector<int>::iterator iter=nodes[q.front()].begin();
                    iter != nodes[q.front()].end(); iter++)
                {
                    if (--enter[*iter] == 0)
                        q.push(*iter);
                }
                q.pop();
            }

            vector<int> out;
            while (!q.empty())
            {
                out.push_back(q.front());
                q.pop();
            }
            return out;
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    graph g(n);
    int a, b;
    
    for (int i=0; i < m; i++)
    {
        cin >> a >> b;
        g.edge(a-1, b-1);
    }
    g.topologicalSortPrint();
}