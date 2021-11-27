//https://www.acmicpc.net/problem/2150
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

class graph
{
    private:
        vector<int> *nodes;
        int size;

        struct sccdata
        {
            bool *isSCC;
            int *visitidx;
            int id;
            vector<vector<int>> scc;
            stack<int> st;
        };

        int SCC_DFS(int cur, sccdata &sd)
        {
            sd.visitidx[cur] = ++sd.id;
            sd.st.push(cur);

            int res = sd.visitidx[cur];
            for (int node : nodes[cur])
            {
                // 아직 방문하지 않았다면
                if (!sd.visitidx[node])
                    res = min(res, SCC_DFS(node, sd));
                // 이미 방문했는데 SCC를 이루고 있지 않다면
                else if (!sd.isSCC[node])
                    res = min(res, sd.visitidx[node]);
            }

            if (res == sd.visitidx[cur])
            {
                vector<int> resSCC;
                while (true)
                {
                    int top = sd.st.top();
                    resSCC.push_back(top);
                    sd.st.pop();
                    sd.isSCC[top] = true;
                    if (top == cur) break;
                }
                sort(resSCC.begin(), resSCC.end());
                sd.scc.push_back(resSCC);
            }
            return res;
        }

    public:
        graph(const int v)
        {
            nodes = new vector<int>[v];
            size = v;
        }

        void edge_dir(const int v1, const int v2)
        {
            nodes[v1].push_back(v2);
        }

        vector<vector<int>> SCC()
        {
            sccdata sd = {
                new bool[size]{ false, },
                new int[size]{ 0, },
                0
            };
            vector<vector<int>> scc;
            // 모든 노드에 대해 SCC를 추출할 것을 보장 (그래프가 끊어진 경우에도)
            for (int i=0; i < size; i++)
                if (!sd.visitidx[i]) SCC_DFS(i, sd);
            sort(sd.scc.begin(), sd.scc.end());
            return sd.scc;
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin >> v >> e;

    graph g(v);
    int v1, v2;
    for (int i=0; i < e; i++)
    {
        cin >> v1 >> v2;
        g.edge_dir(v1-1, v2-1);
    }

    vector<vector<int>> scc = g.SCC();
    cout << scc.size() << '\n';
    for (vector<int> coms : scc)
    {
        for (int c : coms)
            cout << c+1 << ' ';
        cout << "-1\n";
    }
}