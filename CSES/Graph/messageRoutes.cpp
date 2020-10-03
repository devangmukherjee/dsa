#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using f = float;
#define ff first
#define ss second
#define pb push_back
//map for backtracking
map<int, int>parents;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>>adj(n);
    vector<bool>vis(n, false);
    vector<int>ans;
    queue<int>q;

    //push first element into queue
    q.push(0);
    vis[0] = true;
    bool found = false;

    //make adjacency list
    for (int i = 0; i < m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        t1--; t2--;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }

    //BFS
    while (!q.empty())
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            int temp = q.front();
            q.pop();

            //if destination is found
            if (temp == n - 1)
            {
                found = true;
                int dest = n - 1;
                ans.push_back(dest + 1);
                while (true)
                {
                    dest = parents[dest];
                    if (dest == 0)
                    {
                        ans.push_back(1);
                        break;
                    }
                    ans.push_back(dest + 1);
                }
                break;
            }

            //continue with BFS
            for (auto j : adj[temp])
            {
                if (!vis[j])
                {
                    parents[j] = temp;
                    vis[j]=true;
                    q.push(j);
                }
            }
        }
        if (found)break;
    }
    if (found)
    {
        cout << ans.size() << endl;

        //print in reverse
        for (int i=ans.size()-1;i>=0;i--)
        {
            cout << ans[i] << " ";
        }
    }
    else
        cout << "IMPOSSIBLE";

}
