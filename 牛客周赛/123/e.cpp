#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;



//并查集
struct UnionFind {
    vector<int> parent;

    vector<int> rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }

};


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    UnionFind uf(mx + 2);

    int ans = 0;
    set<int> st;
    for(int i = 0; i < n; i++) {
        int cur = a[i];
        st.insert(cur);
        ans++;

        if(st.count(cur -1)) {
            if(uf.find(cur) != uf.find(cur - 1)) {
                uf.unite(cur, cur - 1);
                ans--;
            }
        }

        if(st.count(cur + 1)) {
            if(uf.find(cur) != uf.find(cur + 1)) {
                uf.unite(cur, cur + 1);
                ans--;
            }
        }

        cout << ans << ' ';
    }
    
    return 0;
}