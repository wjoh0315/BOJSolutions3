//https://www.acmicpc.net/problem/11279
#include <iostream>
#include <vector>
using namespace std;

class maxheap
{
    private:
        int heap[200001] = { 0, };
        int last = 0;
        
    public:
        void swap(int *a, int *b)
        {
            int tmp = *a;
            *a = *b;
            *b = tmp;
        }

        void push(int cur)
        {
            // 현재 인덱스는 부모 인덱스 i에 대해 2i + 1 또는 2i + 2의 관계를 가짐
            heap[last] = cur;
            int parent = (last - 1) / 2;
            int pre = last;
            while (heap[parent] < heap[pre])
            {
                swap(&heap[parent], &heap[pre]);
                pre = parent;
                parent = (parent - 1) / 2;
            }
            last++;
        }

        void removemax()
        {
            if (last == 0)
                return;

            heap[0] = 0;
            int i = 0;
            int child1 = 0;
            int child2 = 0;
            while (i < (last - 2)/2 + 1)
            {
                child1 = 2 * i + 1;
                child2 = 2 * i + 2;
                if (heap[child1] > heap[child2])
                {
                    swap(&heap[i], &heap[child1]);
                    i = child1;
                }
                else
                {
                    swap(&heap[i], &heap[child2]);
                    i = child2;
                }
            }
        }

        int max() { return heap[0]; }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int in;
    maxheap mh;
    for (int i=0; i < n; i++)
    {
        cin >> in;
        if (in == 0)
        {
            cout << mh.max() << '\n';
            mh.removemax();
        }
        else
            mh.push(in);
    }
}