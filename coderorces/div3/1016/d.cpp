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

int query(int n, int x, int y) //查询 x ,y 格子里数字
{
    int mid = ((1LL << n)>>1);

    if(n == 1)
    {
        if(x ==1 && y == 1) return 1;
        else if(x ==2 && y == 2) return 2; 
        else if(x ==2 && y== 1) return 3;
        else return 4;
    }

    if(x <= mid && y <= mid)
    {
        return  query(n - 1, x, y);
    }
    else if(x > mid && y > mid)
    {
        return query(n - 1, x - mid, y - mid) + (1LL << (2 * (n - 1)));
    }
    else if(x > mid && y <= mid)
    {
        return query(n - 1, x - mid, y) + 2 * (1LL << (2 * (n - 1)));
    }
    else
    {
        return query(n - 1, x, y - mid) + 3 * (1LL << (2 * (n - 1)));
    }
}

PII g(int n, int num)
{
    int x = 0;
    int y = 0;
    if(n == 1)
    {
        if(num == 1) return {1, 1};
        else if(num == 2) return {2, 2};
        else if(num == 3) return {2, 1};
        else return {1, 2};
    }

    int mid = ((1LL << n)>>1);
    int p = mid * mid;
    if(num <= p)
    {
        auto [a, b] = g(n - 1, num);
        x = a,y=b;
    }
    else if(num <= 2*p)
    {
        auto [a, b] = g(n - 1, num - p);
        x = a + mid, y = b + mid;   
    }
    else if(num <= 3*p)
    {
        auto [a, b] = g(n - 1, num - 2*p);
        x = a + mid, y = b;   
    }
    else
    {
        auto [a, b] = g(n - 1, num - 3*p);
        x = a, y = b + mid;   
    }

    return {x, y};

}
void solve() {
    int n;
    cin >> n ;

    int q;
    cin >> q;
    while(q--)
    {
        string op;
        cin >> op;
        if(op == "->")
        {
            int x ,y;
            cin >> x >> y;
            cout << query(n, x, y) << endl;
        }
        else
        {
            int num;
            cin >> num;
            auto [x, y] = g(n, num);
            cout << x << " " << y << endl;
        }
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