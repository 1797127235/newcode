#include <bits/stdc++.h>
using namespace std;

struct BITMax {
    int n; vector<int> t;
    BITMax(int n=0): n(n), t(n+1,0) {}
    void reset(int _n)
    { n=_n; t.assign(n+1,0); }
    void upd(int i, int val) //维护前缀最大值
    { 
        for(; i<=n; i+=i&-i)
         t[i] = max(t[i], val);
    }
    int qry(int i)
    { 
        int res = 0;
        for(; i>0; i-=i&-i) res = max(res, t[i]);
        return res;
    }
};
//枚举x的所有约数
// cnt[d] 表示当前前缀中，有多少个数能被d整除
// 在树状数组里更新pos = N + 1 - d

static inline void add(int x, vector<int>& cnt, BITMax& bit, int N){
    for(int d=1; 1LL*d*d<=x; ++d){
        if(x%d==0){
            int d1 = d, d2 = x/d;

            cnt[d1]++; 
            bit.upd(N + 1 - d1, cnt[d1]); //倒置下标
            if(d1 != d2){
                cnt[d2]++;
                 bit.upd(N + 1 - d2, cnt[d2]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if(!(cin>>t)) return 0;
    while(t--)
    {
        int n;
         cin>>n;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];

        BITMax bit(n);
        vector<int> cnt(n+1, 0);
        vector<int> ans(n+1, 0);

        int G = 0;
        // 每次新增一个数
        // 更新前缀gcd
        // 更新它所有约数出现次数
        // 查询所有d > gcd 的最大次数 

        //问题是我们要查的是 (G, n] 范围内的最大值
        //所以我们把d倒置一下，变成查询 [1, n-G)

        //于是 ，后缀最大值就变成了前缀最大值问题
        for(int i=1;i<=n;i++){
            G = std::gcd(G, a[i]);
            add(a[i], cnt, bit, n);

            int best = (G < n) ? bit.qry(n - G) : 0;
            ans[i] = best;
        }
        for(int i=1;i<=n;i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
