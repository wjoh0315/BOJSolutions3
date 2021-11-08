//https://www.acmicpc.net/problem/1753
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#define INF 10000000
using namespace std;

class graph
{
    private:
        vector<pair<int, int>> *graphv;
        int size;

    public:
        graph(int n)
        {
            graphv = new vector<pair<int, int>>[n];
            size = n;
        }

        void edge(int v1, int v2, int w)
        {
            graphv[v1].push_back(make_pair(w, v2));
        }

        void dijkstra(int begin)
        {
            // 각 노드별 경로 0 ~ size-1
            int *path = new int[size];
            // 방문 여부
            bool *visited = new bool[size] { false, };
            // 각 노드별 경로를 INF (경로 없음)으로 초기화
            fill_n(path, size, INF);

            // 우선순위 큐
            priority_queue<pair<int, int>, vector<pair<int, int>>, 
                greater<pair<int, int>>> q;
            // 출발점에서부터 시작
            q.push(make_pair(0, begin));
            // 출발점 경로를 0으로 지정
            path[begin] = 0;
            // 출발점 방문
            visited[begin] = true;

            int node;
            while (!q.empty())
            {
                // 가장 거리가 빠른 노드 선택
                node = q.top().second;
                // 방문
                visited[node] = true;
                // 현재 루프에서 해당 노드의 작업이 완료되므로 큐에서 제외
                q.pop();

                // 이웃 노드 순회
                for (vector<pair<int, int>>::iterator iter=graphv[node].begin();
                    iter != graphv[node].end(); iter++)
                {
                    /* 이웃 노드에 지정된 경로가 없거나
                    이웃 노드로 가는 경로가 이미 지정된 경로보다 빠르다면 */
                    if (path[node] + iter->first < path[iter->second])
                    {
                        /* 출발점에서 이웃 노드까지의 거리를 
                        출발점에서 현재 노드까지의 거리 + 현재 노드에서 이웃 노드까지의 거리로 지정 */
                        path[iter->second] = path[node] + iter->first;
                        // 큐에 넣기
                        q.push(make_pair(path[node] + iter->first, iter->second));
                    }
                }
            }
            // 출력
            for (int i=0; i < size; i++)
                cout << (path[i] == INF ? "INF" : to_string(path[i])) << '\n';
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e, k;
    cin >> v >> e >> k;

    graph g(v);
    int v1, v2, w;
    for (int i=0; i < e; i++)
    {
        cin >> v1 >> v2 >> w;
        g.edge(v1-1, v2-1, w);
    }

    g.dijkstra(k-1);
}