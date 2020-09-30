#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using f = float;


void dfs( vector<vector<char>>&grid, int r, int c)
{
    
    int row = grid.size(); int col = grid[0].size();
    if (r < 0 or r>=row or c < 0 or c >= col or grid[r][c] == '#')
    {
        return;
    }
    grid[r][c] = '#';
    dfs(grid, r, c + 1);
    dfs(grid, r - 1, c);
    dfs(grid, r, c - 1);
    dfs(grid, r + 1, c);
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<char>>grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int rooms = 0;
    char dot='.';
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == dot)
            {
                rooms++;
                dfs(grid, i, j);
            }
        }
    }
    cout << rooms;

}
