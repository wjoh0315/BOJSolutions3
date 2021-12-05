//https://www.acmicpc.net/problem/11378
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 2003

int n, m, k;
int con[MAX];
int cap[MAX][MAX] = { { 0, }, };
int flow[MAX][MAX] = { { 0, }, };
vector<int> nodes[MAX];

int networkflow()
{
    int end = n + m + 2;
    int result = 0;
    while (true)
    {
        fill(con, con + n + m + 3, -1);
        queue<int> q;
        q.push(0);
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
        while (now != 0)
        {   
            diff = cap[con[now]][now] - flow[con[now]][now];
            minflow = minflow == -1 ? diff : min(minflow, diff);
            now = con[now];
        }
        // 탐색 결과를 현재 경로의 유량에 반영
        now = end;
        while (now != 0)
        {
            // 정방향 유량 (con[now]에서 now로 흘리는 유량)
            flow[con[now]][now] += minflow;
            // 역방향 유량 (con[now]에서 now로 빠져나가는 유량)
            // now에서 con[now]로 -의 유량을 흘리는 꼴이기 때문
            flow[now][con[now]] -= minflow;
            nodes[now].push_back(con[now]);
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

    /*
    시작 노드 ----------->  직원 -> 일 -> 결과
             ㄴ 벌점 부여 노드 ^
    
    위와 같은 순으로 그래프를 구성
    (시작 노드 -> 벌점 부여 노드, 시작 노드 -> 직원,
    벌점 부여 노드 -> 직원, 직원 -> 일, 일 -> 결과)
    */

    cin >> n >> m >> k;
    // 시작 노드와 벌점 부여 노드를 연결
    nodes[0].push_back(1);
    cap[0][1] = k;

    for (int i=0; i < m; i++)
    {
        nodes[n + i + 2].push_back(n + m + 2);
        cap[n + i + 2][n + m + 2] = 1;
    }

    int s, work;
    for (int i=0; i < n; i++)
    {
        cin >> s;
        nodes[0].push_back(2 + i);
        nodes[1].push_back(2 + i);
        cap[0][2 + i] = 1;
        cap[1][2 + i] = k;
        for (int j=0; j < s; j++)
        {
            cin >> work;
            nodes[2 + i].push_back(n + work + 1);
            cap[2 + i][n + work + 1] = 1;
        }
    }
    cout << networkflow() << '\n';
}