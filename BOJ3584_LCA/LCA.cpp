//https://www.acmicpc.net/problem/3584
#include <iostream>
#include <vector>
using namespace std;

class tree
{
    private:
        // 각 노드별 자식들 (인접 리스트)
        vector<int> *nodes;
        // 각 노드별 깊이
        int *depth;
        // 각 노드별 2^k 번째 부모 (parent[노드][k])
        int **parent;
        // 각 노드별 진입 간선의 갯수 (루트 노드를 제외한 모든 노드는 1)
        int *enter;
        // 루트 노드
        int root;
        // 최대 k
        int exponentMAX;
        // 노드 갯수
        int size;

        void swap(int *a, int *b)
        {
            int tmp = *a;
            *a = *b;
            *b = tmp;
        }

        void updateDFS(int begin)
        {
            for (vector<int>::iterator iter=nodes[begin].begin();
                iter != nodes[begin].end(); iter++)
            {
                if (depth[*iter] == -1)
                {
                    depth[*iter] = depth[begin] + 1;
                    parent[*iter][0] = begin;
                    updateDFS(*iter);
                }
            }
        }

    public:
        tree(int n)
        {
            root = 0;
            size = n;
            nodes = new vector<int>[size];
            enter = new int[size] { 0, };
            depth = new int[size];
            parent = new int*[size];
            fill(depth, depth + size, -1);

            int tmp = size;
            exponentMAX = 0;
            while (tmp > 0)
            {
                exponentMAX++;
                tmp /= 2;
            }

            for (int i=0; i < size; i++)
            {
                parent[i] = new int[exponentMAX+1];
                fill(parent[i], parent[i] + exponentMAX + 1, -1);
            }
        }

        void edge(int parent, int child)
        {
            nodes[parent].push_back(child);
            enter[child]++;
            if (enter[parent] == 0)
                root = parent;
        }

        int LCA(int v1, int v2)
        {
            updateDFS(root);
            for (int i=1; i < exponentMAX+1; i++)
            {
                for (int j=0; j < size; j++)
                {
                    if (parent[j][i-1] != -1)
                        parent[j][i] = parent[parent[j][i-1]][i-1];
                }
            }
            if (depth[v2] < depth[v1])
                swap(&v1, &v2);
            int depthD = depth[v2] - depth[v1];
            int now = 0;
            while (depthD > 0)
            {
                if (depthD % 2 == 1) v2 = parent[v2][now];
                depthD /= 2;
                now++;
            }

            if (v1 == v2)
                return v1;

            for (int i=exponentMAX; i >= 0; i--)
            {
                if (parent[v1][i] != parent[v2][i] && parent[v1][i] != -1)
                {
                    v1 = parent[v1][i];
                    v2 = parent[v2][i];
                }
            }
            return parent[v1][0];
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i=0; i < t; i++)
    {
        int n;
        cin >> n;
    
        tree t(n);
        int a, b;
        for (int j=0; j < n-1; j++)
        {
            cin >> a >> b;
            t.edge(a-1, b-1);
        }
        cin >> a >> b;
        cout << t.LCA(a-1, b-1) + 1 << '\n';
    }
}