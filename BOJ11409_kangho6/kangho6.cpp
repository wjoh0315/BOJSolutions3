//https://www.acmicpc.net/problem/11409
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 802
#define INF 1000000000

int n, m;
int src, sink;
int con[MAX];
int dist[MAX];
bool inq[MAX] = { false, };
int cap[MAX][MAX] = { { 0, }, };
int flow[MAX][MAX] = { { 0, }, };
int cost[MAX][MAX] = { { 0, }, };
vector<int> nodes[MAX];

pair<int, int> MCMF()
{
    int totalcost = 0;
    int totalflow = 0;
    while (true)
    {
        fill(dist, dist + sink + 1, INF);
        fill(con, con + sink + 1, -1);
        
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        inq[src] = true;

        while (!q.empty())
        {
            int cur = q.front();
            inq[cur] = false;
            q.pop();
            
            for (int node : nodes[cur])
            {
                // 유량을 더 흘릴 수 있고 현재 경로를 통한 비용 더 크다면
                if (cap[cur][node] - flow[cur][node] > 0
                    && (dist[node] == INF || dist[cur] + cost[cur][node] > dist[node]))
                {
                    con[node] = cur;
                    dist[node] = dist[cur] + cost[cur][node];
                    if (!inq[node])
                    {
                        q.push(node);
                        inq[node] = true;
                    }
                }
            }
        }
        if (con[sink] == -1) break;

        int minflow = INF;
        int now = sink;
        while (now != src)
        {
            minflow = min(minflow, cap[con[now]][now] - flow[con[now]][now]);
            now = con[now];
        }

        now = sink;
        while (now != src)
        {
            // 더 흘릴 수 있는 유량만큼 비용을 증가시킨다
            totalcost += minflow * cost[con[now]][now];
            // 순방향 유량
            flow[con[now]][now] += minflow;
            // 역방향 유량
            flow[now][con[now]] -= minflow;
            now = con[now];
        }
        totalflow += minflow;
    }

    return make_pair(totalflow, totalcost);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    src = n + m;
    sink = n + m + 1;

    for(int i=0; i < m; i++)
    {
        nodes[n + i].push_back(sink);
        nodes[sink].push_back(n + i);
        cost[n + i][sink] = 0;
        cost[sink][n + i] = 0;
        cap[n + i][sink] = 1;
    }

    int s, w, c;
    for (int i=0; i < n; i++)
    {
        cin >> s;
        nodes[src].push_back(i);
        nodes[i].push_back(src);
        cost[src][i] = 0;
        cost[i][src] = 0;
        cap[src][i] = 1;
        for (int j=0; j < s; j++)
        {
            cin >> w >> c;
            nodes[i].push_back(n + w-1);
            nodes[n + w-1].push_back(i);
            cost[i][n + w-1] = c;
            cost[n + w-1][i] = -c;
            cap[i][n + w-1] = 1;
        }
    }

    pair<int, int> result = MCMF();
    cout << result.first << '\n';
    cout << result.second << '\n';
}