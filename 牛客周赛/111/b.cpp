#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define fi first
#define se second
#define pb push_back
#define endl '\n'
typedef pair<int, int> PII;
typedef long long ll;
#define rep(bg,ed, step) for (int i = bg; i <= ed; i += step)
#define per(bg,ed, step) for (int j = bg; j >= ed; j -= step)
const int INF = 1e18;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;



void solve() {
    int n;
    cin >> n;
    vi a(n),b(n);
    int mxb=0,mna=INF;
    int mxpos=-1,mnpos=-1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i]<mna) mna=a[i],mnpos=i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i]>mxb) mxb=b[i],mxpos=i;
    }
    
    cout << (mnpos + 1) << ' '<<(mxpos+1) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}