/*
    直接考虑答案,左边必须要cnt0个0
    一次操作最多可以让一个1变为0
    所以只需要统计前cnt0个数中1的个数
*/


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
    int n ;
    cin >> n;
    string s;
    cin >> s;
    int cnt0 = ranges::count(s.begin(),s.end(),'0');

    int ans = 0;
    for(int i = 0; i < cnt0; i++)
    {
        if(s[i] == '1') ans++;
    }
    cout << ans << endl;


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}