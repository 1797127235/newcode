#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> v(m);

    for(int i = 0; i < m; i++) {
        cin >> v[i].first >> v[i].second;
    }

    vector<int> vis(n + 1, 0);

    int cnt =  n;
    for(auto &[t,id] : v) {

        bool flag = false;
        if(t == 1) {

            for(int i = 1;i <= n; i++) {
                if(vis[i] == id) {
                    flag = true;
                    break;
                }
            }

            //检测是否已经存在
            if(flag) {
                continue;
            }

            int left = 1e9;
            int right = -1;
            for(int i = 1; i <= n; i++) {
                if(vis[i] != 0) {
                    left = min(left, i);
                    right = max(right, i);
                }
            }
            
            if(right == left)
            {
                //此时只有一个位置被占用
                //要么放在1号位置，要么放在n号位置
                int idx = -1;
                for(int i = 1; i <= n; i++) {
                    if(vis[i] != 0) {
                        idx = i;
                        break;
                    }
                }

                int disl = idx - 1;
                int disr = n - idx;
                if(disl >= disr) {
                    vis[1] = id;
                    cout << 1 << '\n';
                } else {
                    vis[n] = id;
                    cout << n << '\n';
                }
                continue;
            }

            if(left == 1e9 ) {
                vis[1] = id;
                cout << 1 << '\n';
            } else if (right == -1) {
                vis[n] = id;
                cout << n << '\n';
            } else {
                vector<int> pos;
                for(int i = 1; i <= n; i++) {
                    if(vis[i] != 0) {
                        pos.push_back(i);
                    }
                }
                
                int ans = -1;
                int anspos = -1;
                for(int i = 0; i < pos.size() - 1; i++) {
                    int l = pos[i];
                    int r = pos[i + 1];
                    if(r - l > 1) {
                        int mid = (l + r) / 2;
                        if(ans == - 1 || min(mid - l,r - mid ) > ans){
                            ans = min(mid - l, r - mid);
                            anspos = mid;
                        } 
                    }
                }

                if(left != 1) {
                    if(ans == -1 || left - 1 > ans) {
                        ans = left - 1;
                        anspos = 1;
                    }
                }

                if(right != n) {
                    if(ans == -1 || n - right > ans) {
                        ans = n - right;
                        anspos = n;
                    }
                }

                if(anspos != -1) {
                    vis[anspos] = id;
                    cout << anspos << '\n';
                }


            }


        } else {
            for(int i = 1; i <= n; i++) {
                if(vis[i] == id) {
                    vis[i] = 0;
                    cout << i << '\n';
                    break;
                }
                //没有找到
            }
        }


    }







}
