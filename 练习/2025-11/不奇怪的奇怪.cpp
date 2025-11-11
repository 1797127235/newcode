//http://47.117.109.207/problem.php?id=1570

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 998244353;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    vector<ll> p(n);
    p[0] = 1;
    for(ll i = 1; i < n; i++)
    {
        p[i] = (p[i-1] * 2) % mod;
    }


    ll mx = 0;
    ll mn = 0;
    for(ll i = 0; i < n; i++)
    {
        mx = (mx + a[i] * p[i]) % mod;
        mn = (mn + a[i] * p[n - i - 1]) % mod;
    }

    ans = (mx - mn + mod) % mod;
    cout << ans << endl;
    return 0;

}