#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using f = float;
#define ff first
#define ss second


int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  vector<ll>v(n + 1);
  v[0] = 1;
  v[1] = 1;
  ll mod = pow(10,9) +7;
  for (int i = 2; i < n + 1; ++i)
  {
    for (int j = 1; j < 7; j++)
    {
      if (j <= i)
      {
        v[i] += v[i - j];
        v[i]=v[i]%mod;
      }
    }
  }
  if (n == 0)
    cout << 0;
  if (n == 1)
    cout << 1;
  else
  {
    ll ans = v[n];
    cout << ans<<endl;
    
  }
}
