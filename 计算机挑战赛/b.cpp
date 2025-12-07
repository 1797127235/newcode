#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;

void dfs(int pos, int lastIdx, const string &t, int m, vector<int> &perm, vector<bool> &used, vector<vector<int>> &ans) {
        if (pos == m) {
            ans.push_back(perm);
            return;
        }
        for (int i = 0; i < m; ++i) {
            if (used[i]) continue;
            if (lastIdx != -1 && t[i] == t[lastIdx]) continue;
            used[i] = true;
            perm[pos] = i;         
            dfs(pos + 1, i, t, m, perm, used, ans);
            used[i] = false;
        }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    string s;
    cin >> s;

    string t;
    for (char c : s) {
        if (c != 'N') t.push_back(c);
    }

    int m = t.size();
    if (m == 0) {
        cout << "NO\n";
        return 0;
    }
    if (m == 1) {
        cout << "YES\n1\n";
        return 0;
    }

    vector<int> perm(m);
    vector<bool> used(m, false);
    vector<vector<int>> ans;


    dfs(0, -1, t, m, perm, used, ans);

    if (ans.empty()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (auto &v : ans) {
            for (int idx : v) cout << (idx + 1);  
            cout << '\n';
        }
    }

    return 0;
}
