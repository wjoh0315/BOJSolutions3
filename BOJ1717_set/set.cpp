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
            for (int i=0; i < n+1; i++)
                graph[i] = i;
            size = n+1;
        }

        int Find(int cur)
        {
            if (graph[cur] == cur)
                return cur;
            graph[cur] = Find(graph[cur]); 
            return graph[cur];
        }

        void Union(int a, int b)
        {
            a = Find(a);
            b = Find(b);
            if (a == b)
                return;
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