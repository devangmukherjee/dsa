#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using f = float;
#define ff first
#define ss second

int row[4] = {0, -1, 0, 1};
int col[4] = {1, 0, -1, 0};

pair<int, int>start, dest, temp;

bool isvalid(vector<vector<char>> &grid, int r, int c)
{
    return (r >= 0 and r<grid.size() and c >= 0 and c < grid[0].size());
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<char>>grid(n, vector<char>(m));
    vector<vector<bool>>vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                start = make_pair(i, j);
            }
        }
    }
    queue<pair<int, int>>q;
    vis[start.ff][start.ss] = true;
    q.push(start);
    map<pair<int, int>, pair<pair<int, int>, char>> parents;

    while (!q.empty())
    {
        temp=q.front();
        q.pop();
        int a=temp.first;
        int b=temp.second;        
        for(auto i:row)
        {
            for(auto j:col)
            {
                if (isvalid(grid, a+i, b+j)  && (abs(i) != abs(j)) && !vis[a+i][b+j] && (grid[a+i][b+j] == '.' || grid[a+i][b+j] == 'B'))
                {
                    char c;
                    if (i==0 and j == 1)
                        c = 'R';
                    if (i==1 and j == 0)
                        c = 'D';
                    if (i==0 and j == -1)
                        c = 'L';
                    if (i==-1 and j == 0 )
                        c = 'U';
                    parents[make_pair(a+i, b+j)] = make_pair(make_pair(temp.ff, temp.ss), c);

                    if (grid[a+i][b+j] == 'B')
                    {
                        dest = make_pair(a+i, b+j);
                        string s = "";
                        while (true)
                        {
                            s += parents[dest].ss;
                            dest = parents[dest].ff;
                            if (dest.ff == start.ff and dest.ss == start.ss)
                            {
                                break;
                            }
                        }
                        reverse(s.begin(), s.end());
                        cout << "YES" << endl;
                        cout << s.length() << endl;
                        cout << s;
                        return 0;
                    }
                    vis[a+i][b+j] = 1;
                    q.push(make_pair(a+i, b+j));
                }
            }
        }
    }
    cout << "NO" << endl;
}
