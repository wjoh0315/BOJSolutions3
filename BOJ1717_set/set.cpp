//https://www.acmicpc.net/problem/1717
#include <iostream>
using namespace std;

class UnionFind
{
    private:
        int *graph;
        int size;

    public:
        UnionFind(int n)
        {
            graph = new int[n+1];
            // 모든 노드의 부모를 자기 자신으로 초기화
            for (int i=0; i < n+1; i++)
                graph[i] = i;
            size = n+1;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    UnionFind uf(n);
    int cmd, a, b;
    for (int i=0; i < m; i++)
    {
        cin >> cmd >> a >> b;
        if (cmd == 0)
            uf.Union(a, b);
        else if (cmd == 1)
            cout << (uf.Find(a) == uf.Find(b) ? "YES" : "NO") << '\n';;
    }
}