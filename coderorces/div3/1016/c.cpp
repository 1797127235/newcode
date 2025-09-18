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
    int x,k;
    cin>>x>>k;
    int len = 0;
    int tmp = x;
    while(tmp)
    {
        len++;
        tmp/=10;
    }

    auto check=[&](int x){
        if(x == 1) return false;
        if(x == 2) return true;

        for(int i = 2; i * i <= x; i++)
        {
            if(x % i == 0) return false;
        }
        return true;
    };

    auto change=[&](int n)->int{
    n+=1;
    int res=pow(10,n)-1;
    res/=9;
    return res;
    };
    if(k == 1 && check(x))
    {
        cout<<"YES"<<endl;
        return;
    }

    if(x == 1)
    {
        int q = pow(10,len);
        int t = (pow(q,k) -1) /(q-1);
        if(check(t)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;                             
    }
    else
    {
        cout << "NO" << endl;
    }


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}