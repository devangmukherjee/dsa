  #include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using f = float;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
ll mod=1e9+7;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n);
    vector<ll>ind(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        ind[b]++;
    }
    queue<ll>q;
    for (int i = 1; i < n; i++)
    {
        if (ind[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        ll curr = q.front();
        q.pop();
        for (auto i : adj[curr])
        {
            ind[i]--;
            if (ind[i] == 0)
                q.push(i);
        }
    }
    vector<ll>count(n,0);
    count[0] = 1;
    q.push(0);
    while (!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(auto i:adj[curr])
        {
            count[i]=(count[curr]+count[i]);
            count[i]%=mod;
            ind[i]--;
            if(ind[i]==0)
                q.push(i);
        }
    }
    cout<<count[n-1];



}
