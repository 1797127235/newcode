#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int dx[8] = {1, 2,  2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1,  1,  2};
int main()
{
    int n;
    cin >> n;
    
    map<pair<int,int> ,int> mp;
    
    for(int i =1 ;i<=n ;i++)
    {
        int x,y;
        cin>>x>>y;
        for(int k=0 ; k < 8 ;k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            mp[{nx,ny}]++;
        }
    }
    int ans = 0;
    int x =0;
    int y =0;
    for(auto &[p,cnt] : mp)
    {
        if(cnt > ans && p.first > 0 && p.second > 0)
        {
            ans = cnt;
            x=p.first;
            y=p.second;
        }
    }
    cout<<x<<' '<<y<<endl;
}