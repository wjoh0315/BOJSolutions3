//https://www.acmicpc.net/problem/11725
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class graph
{
    private:
        // 인접 리스트로 구현
        vector<int> *graphv;
        // 노드의 개수
        int size;

    public:
        graph(int n)
        {
            // 노드의 개수만큼 인접 리스트 메모리 할당
            graphv = new vector<int>[n];
            // size를 노드의 개수 n으로 지정
            size = n;
        }

        void edge(int v1, int v2)
        {
            /* 두 노드의 관계 (부모 or 자식)는 알 수 없으므로
            두 노드 모두에 서로를 연결하는 무방향 간선임을 알림 */
            graphv[v1].push_back(v2);
            graphv[v2].push_back(v1);
        }

        void printparents()
        {
            // 각 노드의 부모
            int *parents = new int[size] { 0, };
            // 각 노드의 방문 여부
            bool *visited = new bool[size] { true, };
            // 큐 (선입선출)
            queue<int> q;
            // 루트인 노드 1 (인덱스상 0)부터 작업 시작
            q.push(0);
            while (!q.empty())
            {
                // 현재 노드 방문
                visited[q.front()] = true;
                // BFS(너비 우선 탐색), 이웃 노드 순회
                for (vector<int>::iterator iter = graphv[q.front()].begin();
                    iter != graphv[q.front()].end(); iter++)
                {
                    // 이미 방문한 노드라면 그 노드는 현재 노드의 부모로, 건너뛰기
                    if (visited[*iter])
                        continue;
                    // 해당 노드를 큐에 넣기
                    q.push(*iter);
                    // 현재 노드가 해당 노드의 부모임을 알리기 (인덱스상의 값이므로 1을 더해 저장)
                    parents[*iter] = q.front() + 1;
                }
                // 작업 완료
                q.pop();
            }
            // 노드 2 (인덱스상 1)부터 노드 n까지 부모 출력
            for (int i=1; i < size; i++)
                cout << parents[i] << '\n';
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int v1, v2;
    graph g(n);
    for (int i=0; i < n-1; i++)
    {
        cin >> v1 >> v2;
        g.edge(v1-1, v2-1);
    }

    g.printparents();
}