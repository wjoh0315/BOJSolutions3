//https://www.acmicpc.net/problem/17412
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 400

int n, p;
int con[MAX];
int cap[MAX][MAX] = { { 0, }, };
int flow[MAX][MAX] = { { 0, }, };
vector<int> nodes[MAX];

int networkflow(int begin, int end)
{
    int result = 0;
    while (true)
    {
        fill(con, con + n, -1);
        queue<int> q;
        q.push(begin);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int node : nodes[cur])
            {
                // 유량을 더 흘릴 수 있고 아직 이웃 노드를 방문하지 않은 경우
                if (con[node] == -1 
                && cap[cur][node] - flow[cur][node] > 0)
                {
                    q.push(node);
                    con[node] = cur;
                    if (node == end) break;
                }
            }
        }
        // 끝 지점으로 유량을 흘릴 수 있는 경우가 없다면 종료
        if (con[end] == -1) break;
        
        // 현재 경로에 얼마나 더 유량을 흘릴 수 있는지 탐색
        int now = end;
        int diff = 0;
        int minflow = -1;
        while (now != begin)
        {   
            diff = cap[con[now]][now] - flow[con[now]][now];
            minflow = minflow == -1 ? diff : min(minflow, diff);
            now = con[now];
        }
        // 탐색 결과를 현재 경로의 유량에 반영
        now = end;
        while (now != begin)
        {
            // 정방향 유량 (con[now]에서 now로 흘리는 유량)
            flow[con[now]][now] += minflow;
            // 역방향 유량 (con[now]에서 now로 빠져나가는 유량)
            // now에서 con[now]로 -의 유량을 흘리는 꼴이기 때문
            flow[now][con[now]] -= minflow;
            now = con[now];
        }
        // 유량을 더 흘린만큼 결과에 더한다
        result += minflow;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> p;

    int v1, v2;
    for (int i=0; i < p; i++)
    {
        cin >> v1 >> v2;
        nodes[v1-1].push_back(v2-1);
        nodes[v2-1].push_back(v1-1);
        cap[v1-1][v2-1] = 1;
    }
    cout << networkflow(0, 1) << '\n';
}