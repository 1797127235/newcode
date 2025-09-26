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

// Python-like print
template<typename... Args>
void print(Args... args) {
    ((cout << args << " "), ...);
    cout << endl;
}

void solve() {
    int n,d;
    cin >> n >> d;
    string s;
    cin >> s;
    if(s.find('0')!=string::npos)
    {
        print(0);
        return;
    }

    sort(s.begin(),s.end());
    auto check = [](string& a, string& b) {
        if (b.empty()) return true;
        if (a.empty()) return false;
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    };

    string ans;
    do{
        int r = 0;
        string pre;
        for(int i = 0; i < n; i++)
        {
            r = (r*10 + (s[i]-'0'))%d;
            pre+=s[i];
            if(r==0 && check(pre,ans))
            {
                ans = pre;
            }
        }

    }while(next_permutation(s.begin(),s.end()));

    if(ans.empty()) print(-1);
    else print(ans);

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}