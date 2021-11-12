//https://www.acmicpc.net/problem/1197
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

class UnionFind
{
    private:
        int *graph;
        int size;

    public:
        UnionFind(int n)
        {
            graph = new int[n];
            // 모든 노드의 부모를 자기 자신으로 초기화
            for (int i=0; i < n; i++)
                graph[i] = i;
            size = n;
        }

        int Find(int cur)
        {
            // 해당 노드의 부모가 자신이라면 탐색 종료
            if (graph[cur] == cur)
                return cur;
            // 해당 노드의 부모를 재귀적으로 탐색 및 트리 (그래프) 재구성
            graph[cur] = Find(graph[cur]); 
            return graph[cur];
        }

        void Union(int a, int b)
        {
            // 두 노드의 부모 탐색
            a = Find(a);
            b = Find(b);
            // 두 노드의 부모가 같다면 결합 중단
            if (a == b)
                return;
            // 인덱스상 루트 노드가 앞순서인 트리에 나머지 트리 결합 (편의)
            graph[a<b?a:b] = a>b?a:b;
        }
};

int solve(int v, int e)
{
    int a, b, c;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>> pq;
    for (int i=0; i < e; i++)
    {
        cin >> a >> b >> c;
        pq.push(make_tuple(c, a-1, b-1));
    }   

    int sum = 0;
    int count = 0;
    UnionFind uf(v);
    int *visited = new int[v] { false, };
    while (!pq.empty() && count < v - 1)
    {
        if (uf.Find(get<1>(pq.top())) 
            == uf.Find(get<2>(pq.top())))
        {
            pq.pop();
            continue;
        }
        uf.Union(get<1>(pq.top()), get<2>(pq.top()));
        visited[get<1>(pq.top())] = true;
        visited[get<2>(pq.top())] = true;
        sum += get<0>(pq.top());
        count++;
        pq.pop();
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin >> v >> e;

    cout << solve(v, e) << '\n';
}