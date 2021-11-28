//https://www.acmicpc.net/problem/11375
#include <iostream>
#include <vector>
using namespace std;

class binetwork
{
    private:
        vector<int> *nodes;
        int *tasks;
        int *done;
        int nodesize;
        int tasksize;

        bool DFS_BM(int v, bool *done)
        {
            for (int t : nodes[v])
            {
                if (done[t]) continue;
                done[t] = true;
                if (tasks[t] == 0 || DFS_BM(tasks[t]-1, done))
                {
                    tasks[t] = v + 1;
                    return true;
                }
            }
            return false;
        }

    public:
        binetwork(int n, int m)
        {
            nodes = new vector<int>[n];
            tasks = new int[m] { 0, };
            nodesize = n;
            tasksize = m;
        }

        void insert(int v, int t)
        {
            nodes[v].push_back(t);
        }

        int BipartiteMatching()
        {
            int count = 0;
            for (int i = 0; i < nodesize; i++)
            {
                bool *done = new bool[tasksize] { false, };
                if (DFS_BM(i, done)) count++;
            }
            return count;
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int taskN, task;
    binetwork bw(n, m);
    for (int i=0; i < n; i++)
    {
        cin >> taskN;
        for (int j=0; j < taskN; j++)
        {
            cin >> task;
            bw.insert(i, task-1);
        }
    }

    int match = bw.BipartiteMatching();
    cout << match << '\n';
}