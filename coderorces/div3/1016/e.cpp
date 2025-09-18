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
const int mod=1e9+7;
void solve() {
    int n,k;
    cin>>n>>k;
    vi a(n+1);
    map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        mp[a[i]] ++;
    }
    // //tick 当前段编号
    // auto check= [&](int x) {
    //     if (x == 0) return true; // 任意段 MEX >= 0
    //     vector<int> seen(x, -1);
    //     int tick = 0;//
    //     int have = 0;//当前段数字
    //     int seg = 0;//分成段数

    //     for(int i = 1; i <= n; i++) {
    //         int v = a[i];
    //         if (v < x && seen[v] != tick){
    //             seen[v] = tick; //当前段见过 v
    //             if (++have == x) {           // 收齐 0..x-1
    //                 seg++;
    //                 if (seg >= k) return true;
    //                 tick++;                  // 开新段（逻辑清空）
    //                 have = 0;
    //             }
    //         }
    //     }
    //     return false;
    // };

    auto check =[&](int x)
    {
        if(x == 0) return true;
        int have = 0;
        int seg = 0;
        vi seen(n+1, -1);
        for(int i = 1; i <= n ; i++)
        {
            int v = a[i];
            if(v < x && seen[v] != seg)
            {
                seen[v]=seg;
                if(++have == x)
                {
                    seg++;
                    if(seg >=k) return true;
                    have = 0;
                }
            }
        }

        return false;
    };
    // 分成k个  最大化 最小
    //如果想让最小Mex>=x ,就必须能把整个数组切成 k 段“好段”，每段都含有 0..x-1
    int l = 0;
    int r = n + 1;
    while(l < r)
    {
        int mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }

    cout << l << endl;


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}