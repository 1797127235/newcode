#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x < 600)
        v.push_back(x);
    }
    n = v.size();
    map<int,int> mp;
    int ans = 1;
    //滑动窗口，维护区间最大和最小
    int mx = 0, mn = 1e9;

    int l = 0;
    for(int r = 0; r < n; r++)
    {
        mp[v[r]]++;
        mx = max(mx,v[r]);
        mn = min(mn,v[r]);
        while(mx - mn > k)
        {
            mp[v[l]]--;
            if(mp[v[l]] == 0)
            {
                if(v[l] == mx)
                {
                    //更新最大值
                    mp.erase(mx);
                    if(!mp.empty())
                    {
                        mx = prev(mp.end())->first;
                    }
                    else
                    {
                        mx = 0;
                    }
                }
                if(v[l] == mn)
                {
                    //更新最小值
                    mp.erase(mn);
                    if(!mp.empty())
                    {
                        mn = mp.begin()->first;
                    }
                    else
                    {
                        mn = 1e9;
                    }
                }
                mp.erase(v[l]);
            } 
            l++;
        }
        ans = max(ans,r - l + 1);
    }
    if(ans < 2)
    {
        cout << "NO" <<'\n';
    }
    else
    {
        cout << "YES" << '\n';
        cout << ans << '\n';
    }
    return 0;
}