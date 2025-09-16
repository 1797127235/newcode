#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n' 
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
typedef pair<int, int> PII;
typedef long long ll;
#define rep(bg,ed, step) for (int i = bg; i <= ed; i += step)
#define per(bg,ed, step) for (int j = bg; j >= ed; j -= step)
const int INF = 1e18;
const int N = 1e5 + 10;
const int mod=1e9+7;
struct Point{
    int x;
    int y;
    int w; //权重
};
void solve() {
    int n;
    cin >> n;

    vector<PII> a(n + 1);

    map<PII,int> cnt;

    for(int i = 1; i <=n ; i++)
    {
        cin >> a[i].first >> a[i].second;
        cnt[a[i]]++;
    }

    vector<Point> v;

    for(auto &[p,c] : cnt)
    {
        v.push_back({p.first, p.second, c});
    }

    sort(v.begin(), v.end(), [&](Point &a, Point &b){
        return a.x < b.x;
    });

    int ans = 0;
    map<int ,int> mpy;

    for(auto &[x, y, w] : v)
    {
        int line = 0;
        if(cnt.count({x,y+1}))
        {
            line = w * cnt[{x,y+1}];
        }

        if(mpy.count(y))
        {
            ans += line * mpy[y];
        }
        if(line > 0)
        {
            mpy[y] += line;
        }
    }

    sort(v.begin(), v.end(), [&](Point &a, Point &b){
        return a.y < b.y;
    });

    map<int ,int> mpx;

    for(auto &[x, y, w] : v)
    {
        int line = 0;
        if(cnt.count({x+1,y}))
        {
            line = w * cnt[{x+1,y}];
        }

        if(mpx.count(x))
        {
            ans += line * mpx[x];
        }
        if(line > 0)
        {
            mpx[x] += line;
        }
    }


    for(int i = 1; i <= n; i++)
    {
        auto [x,y] = a[i];
        int c = 1;
        if(cnt.count({x+1,y}))
        {
            c*= cnt[{x+1,y}];
        }
        else c = 0;

        if(cnt.count({x,y+1}))
        {
            c*= cnt[{x,y+1}];
        }
        else c = 0;

        if(cnt.count({x+1,y+1}))
        {
            c*= cnt[{x+1,y+1}];
        }
        else c = 0;

        ans -= c;
    }
    cout << ans << endl;





}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}