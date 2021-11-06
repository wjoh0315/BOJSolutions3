//https://www.acmicpc.net/problem/1260
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class graph
{
    private:
        vector<int> *graphv;
        int size;

        void sortedge(int v1, int v2)
        {
            stack<int> tmp;
            while (!graphv[v1].empty() && graphv[v1].back() > v2)
            {
                tmp.push(graphv[v1].back());
                graphv[v1].pop_back();
            }
            graphv[v1].push_back(v2);
            while (!tmp.empty())
            {
                graphv[v1].push_back(tmp.top());
                tmp.pop();
            }
        }

        void DFSf(int cur, bool* visited)
        {
            cout << cur + 1 << ' ';
            visited[cur] = true;
            
            for (vector<int>::iterator iter = graphv[cur].begin();
                iter != graphv[cur].end(); iter++)
            {
                if (visited[*iter])
                    continue;

                this->DFSf(*iter, visited);
            }
        }

    public:
        graph(int n)
        {
            graphv = new vector<int>[n];
            size = n;
        }

        void edge(int v1, int v2)
        {
            if (v1 >= 1000)
                return;

            this->sortedge(v1, v2);
            this->sortedge(v2, v1);
        }

        void DFS(int begin)
        {
            bool *visited = new bool[size] { false, };
            this->DFSf(begin, visited);
            cout << '\n';
        }

        void BFS(int begin)
        {
            bool *visited = new bool[size] { false, };
            queue<int> q;
            q.push(begin);
            while (!q.empty())
            {
                cout << q.front() + 1 << ' ';
                visited[q.front()] = true;
                for (vector<int>::iterator iter = graphv[q.front()].begin();
                    iter != graphv[q.front()].end(); iter++)
                {
                    if (!visited[*iter])
                    {
                        visited[*iter] = true;
                        q.push(*iter);
                    }
                }
                q.pop();
            }
            cout << '\n';
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, v;
    cin >> n >> m >> v;

    graph g(n);
    int v1, v2;
    for (int i=0; i < m; i++)
    {
        cin >> v1 >> v2;
        g.edge(v1-1, v2-1);
    }
    
    g.DFS(v-1);
    g.BFS(v-1);
}