//https://www.acmicpc.net/problem/2630
#include <iostream>
using namespace std;

void solve(int *white, int *blue, 
int **quadtree, int n, int bx, int by)
{
    bool success = true;
    int pre = quadtree[by][bx];
    for (int y=by; y < by+n; y++)
    {
        for (int x=bx; x < bx+n; x++)
        {
            success = pre == quadtree[y][x];
            if (!success)
                break;
        }
        if (!success)
            break;
    }
    
    if (success)
    {
        *white += pre == 0;
        *blue += pre == 1;
        return;
    }
    else
    {
        solve(white, blue, quadtree, n/2, bx, by);
        solve(white, blue, quadtree, n/2, bx+n/2, by);
        solve(white, blue, quadtree, n/2, bx, by+n/2);
        solve(white, blue, quadtree, n/2, bx+n/2, by+n/2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int white = 0;
    int blue = 0;
    int **quadtree = new int*[n];
    for (int y=0; y < n; y++)
    {
        quadtree[y] = new int[n];
        for (int i=0; i < n; i++)
            cin >> quadtree[y][i];
    }

    solve(&white, &blue, quadtree, n, 0, 0);
    cout << white << '\n';
    cout << blue << '\n';
}