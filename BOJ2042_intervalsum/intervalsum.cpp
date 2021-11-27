//https://www.acmicpc.net/problem/2042
#include <iostream>
#include <math.h>
using namespace std;

class SegmentTree
{
    private:
        long long int *segments;
        long long int *array;
        int size;

    public:
        SegmentTree(long long int *arr, int n)
        {
            array = arr;
            segments = new long long int[1 << ((int)ceil(log2(n)) + 1)];
            size = n;
            set(0, size-1, 1);
        }

        long long int set(int begin, int end, int parent)
        {
            if (begin >= end)
            {
                segments[parent] = array[begin];
                return segments[parent];
            }
            int mid = (begin + end) / 2;
            segments[parent] = set(begin, mid, 2 * parent) 
                + set(mid + 1, end, 2 * parent + 1);
            return segments[parent];
        }

        void update(int ch, long long int diff, int idx, int begin, int end)
        {
            if (ch < begin || ch > end)
                return;
            segments[idx] += diff;
            if (begin >= end)
                return;
            int mid = (begin + end) / 2;
            update(ch, diff, 2 * idx, begin, mid);
            update(ch, diff, 2 * idx + 1, mid + 1, end);
        }

        long long int intervalsum(int idx, int begin, int end, int st, int fi)
        {
            if (st <= begin && fi >= end)
                return segments[idx];
            else if (st > end || fi < begin)
                return 0;
            int mid = (begin + end) / 2;
            return intervalsum(2 * idx, begin, mid, st, fi)
                + intervalsum(2 * idx + 1, mid + 1, end, st, fi);
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    long long int *arr = new long long int[n];
    for (int i=0; i < n; i++)
        cin >> arr[i];

    SegmentTree st(arr, n);
    int a, b;
    long long int c;
    for (int i=0; i < m+k; i++)
    {
        cin >> a >> b;
        cin >> c;
        if (a == 1)
        {
            st.update(b-1, c - arr[b-1], 1, 0, n-1);
            arr[b-1] = c;
        }
        else if (a == 2)
            cout << st.intervalsum(1, 0, n-1, b-1, c-1) << '\n';
    }
}