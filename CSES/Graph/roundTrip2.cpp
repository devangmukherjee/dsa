#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using f = float;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

//cycle finding
vector<vector<ll>>adj;
stack<ll> s; 
vector<bool>vis; 
vector<bool>presentInStack;
bool cycle(ll u)
{
    vis[u] = true;
    s.push(u);
    presentInStack[u] = true;
    for(auto v: adj[u])
    {
        if(!vis[v])
            if(cycle(v))
                return true;
 
        if(presentInStack[v])
        {
            s.push(v);
            return true;
            //no more dfs;
        }
    }
    s.pop();
    presentInStack[u] = false;
    return false;
    //no cycle was detected
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, e;
    cin >> n >> e ;
    adj.resize(n);
    vis.resize(n);
    presentInStack.resize(n);
    for (ll i = 0; i < e; i++) {
        ll a, b;
        cin >> a >> b;  
        a--; b--;
        adj[a].push_back(b);
    }
    for (ll j = 0; j < n; j++)
    {
        if (!vis[j])
        {
            if (cycle(j))
                break;
        }
    }

    if (!s.empty())
    {
        vector<ll>ans;
        ll temp = s.top();
        while (!s.empty())
        {
            ans.pb(s.top());
            s.pop();
            if (ans.back() == temp and ans.size() > 2)
                break;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (auto i : ans)
            cout << i+1 << ' ';
        return 0;
    }
    else {
        cout << "IMPOSSIBLE";
    }
}
