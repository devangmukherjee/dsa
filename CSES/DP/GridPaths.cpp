#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using f = float;
#define ff first
#define ss second
const int mod = 1e9 + 7;
const int mx = 100;
//int dp[1000001];
int v[mx + 1];


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    char dp[n][n];
    int path[n][n];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> dp[i][j];
            path[i][j] = 0;
        }
    }

    path[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i)
                path[i][j] += path[i - 1][j];
            if (j)
                path[i][j] += path[i][j - 1];
            if (dp[i][j] == '*')
                path[i][j] = 0;
            path[i][j] %= mod;

        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << path[i][j] << '\t';
    //     }
    //     cout << endl;
    // }
    if (dp[0][0] == '*')
        cout << 0;
    else
        cout << path[n - 1][n - 1] % mod;
    return 0;

}
