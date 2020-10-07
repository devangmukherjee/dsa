#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using f = float;
#define ff first
#define ss second
#define pb push_back
int x[4] = {0, -1, 0, 1};
int y[4] = {1, 0, -1, 0};
map<pair<int, int>, pair<int, int>>parent;

void Mmarkdist(vector<vector<char>> &v, vector<vector<int>> &mdist, vector<vector<bool>> &vis, vector<pair<int, int>> mplaces)
{
    queue<pair<int, int>> q;
    for (auto i : mplaces)
    {
        q.push(i);
        int r = i.ff;
        int c = i.ss;
        mdist[r][c] = 0;
        vis[r][c] = true;
    }

    int a, b;
    int level = 0;
    while (!q.empty())
    {
        int len = q.size();
        level++;
        for (int i = 0; i < len; i++)
        {
            pair<int, int> curr = q.front();
            q.pop();
            mdist[curr.ff][curr.ss] = min(level - 1, mdist[curr.ff][curr.ss]);
            for (int j = 0; j < 4; j++)
            {
                a = curr.ff + x[j];
                b = curr.ss + y[j];
                if (a >= 0 and a<v.size() and b >= 0 and b < v[0].size() and !vis[a][b])
                {
                    if (v[a][b] != '#')
                    {
                        vis[a][b] = true;
                        pair<int, int>temp = make_pair(a, b);
                        q.push(temp);
                    }
                }
            }

        }
    }
}

void markdist(vector<vector<char>> &v, vector<vector<int>> &mdist, vector<vector<bool>> &vis, int r, int c)
{
    pair<int, int> src = make_pair(r, c);
    queue<pair<int, int>> q;
    q.push(src);
    mdist[r][c] = 0;
    vis[r][c] = true;
    int a, b;
    int level = 0;
    while (!q.empty())
    {
        int len = q.size();
        level++;
        for (int i = 0; i < len; i++)
        {
            pair<int, int> curr = q.front();
            q.pop();
            mdist[curr.ff][curr.ss] = min(level - 1, mdist[curr.ff][curr.ss]);
            for (int j = 0; j < 4; j++)
            {
                a = curr.ff + x[j];
                b = curr.ss + y[j];
                if (a >= 0 and a<v.size() and b >= 0 and b < v[0].size() and !vis[a][b])
                {
                    if (v[a][b] != '#')
                    {
                        vis[a][b] = true;
                        pair<int, int>temp = make_pair(a, b);
                        parent[temp] = curr;
                        q.push(temp);
                    }
                }
            }

        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<int>> mdist(n, vector<int>(m, 1001));
    vector<vector<int>> adist(n, vector<int>(m, 1001));
    vector<vector<int>> ans(n, vector<int>(m));
    pair<int, int> start;
    bool dotexi=false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if(v[i][j]=='.')
                dotexi=true;
            if (v[i][j] == '#')
            {
                mdist[i][j] = 1001;
                adist[i][j] = 1001;
            }
            if (v[i][j] == 'A')
            {
                start = make_pair(i, j);
            }
        }
    }
    if(start.ff==n-1 or start.ss==m-1)
    {
        cout<<"YES"<<endl;
        cout<<0;
        exit(0);
    }
    vector<pair<int, int>>mplaces;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'M')
            {
                pair<int, int>mtemp = make_pair(i, j);
                mplaces.pb(mtemp);
            }
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    Mmarkdist(v, mdist, vis, mplaces);
    vector<vector<bool>> vis2(n, vector<bool>(m, false));
    markdist(v, adist, vis2, start.ff, start.ss);


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans[i][j] = adist[i][j] - mdist[i][j];
        }
    }

    bool possible = false, btfound = false;
    vector<char>bt;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 or i == n - 1 or j == 0 or j == m - 1)
            {
                if (ans[i][j] < 0)
                {
                    possible = true;
                    pair<int, int>par = make_pair(i, j);
                    pair<int, int>childcurr;
                    char c;
                    while (true)
                    {
                        childcurr = par;
                        par = parent[par];
                        int m = par.ff - childcurr.ff;
                        int n = par.ss - childcurr.ss;

                        if (m == 0 and n == 1)
                            c = 'L';
                        if (m == -1 and n == 0)
                            c = 'D';
                        if (m == 0 and n == -1)
                            c = 'R';
                        if (m == 1 and n == 0)
                            c = 'U';

                        bt.pb(c);

                        if(par==start)
                            break;
                    }
                }
            }
        }
        if (possible)break;
    }
 
    if(n==1 and m==1)
    {
        cout<<"YES"<<endl;
        cout<<0;
        exit(0);
    }

    if (n>1 and m>1 and possible)
    {
        cout << "YES" << endl;
        cout << bt.size() << endl;
        reverse(bt.begin(), bt.end());
        for (auto i : bt)
            cout << i;
    }
    else
        cout << "NO";



}


