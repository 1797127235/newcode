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
  int n;
  std::cin >> n;
  std::vector<int> p(n);
  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
  }  
 
  int l = 0, r = n - 1;
  for (int i = 1; i <= n; i++) {
    if (p[l] == i) {
      l++;
    } else if (p[r] == i) {
      r--;
    } else{
     std::cout << "NO" << endl;
      return;
    }
  }
    std::cout << "YES" << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}