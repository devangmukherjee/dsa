#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using f = float;
#define ff first
#define ss second
#define pb push_back

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
    vector<vector<int>>adj(n);
    vector<int>team(n,0);
    bool possible=true;
    for (int i = 0; i < m; i++)
    {
        int te1, te2;
        cin >> te1 >> te2;
        te1--; te2--;
        adj[te1].pb(te2);
        adj[te2].pb(te1);
    }
    for(int i=0;i<n;i++)
    {
        if(team[i]==1 || team[i]==-1)
            continue;
        queue<int>q;
        q.push(i);
        team[i]=1;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(auto j:adj[curr])
            {
                if(team[j]==0)
                {
                    team[j]=-team[curr];
                    q.push(j);
                }
                if(team[j]==team[curr])
                {
                    possible=false;
                    break;
                }
            }
            if(!possible)break;
        }
        if(!possible)break;
    }
    if(!possible)
        cout<<"IMPOSSIBLE";
    else
    {
        for(auto i:team)
        {
            if(i==-1)
                cout<<2<<" ";
            else
                cout<<1<<" ";
        }
    }


}
