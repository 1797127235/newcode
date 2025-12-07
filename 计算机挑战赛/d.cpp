#include <bits/stdc++.h>
using namespace std;

struct Core {
    int u, v;
    bool ok;
    bool empty;
};


const int MAXN = 2000000 + 5; 
const int LOGN = 20;

int n, q;
vector<int> g[MAXN];

int up[LOGN][MAXN];
int depthArr[MAXN];



void dfs_build(int root = 1) {

    vector<int> st;
    st.push_back(root);
    up[0][root] = 0;
    depthArr[root] = 0;

    while (!st.empty()) {
        int u = st.back(); st.pop_back();
        for (int v : g[u]) {
            if (v == up[0][u]) continue;
            up[0][v] = u;
            depthArr[v] = depthArr[u] + 1;
            st.push_back(v);
        }
    }

    for (int k = 1; k < LOGN; ++k) {
        for (int v = 1; v <= n; ++v) {
            int mid = up[k-1][v];
            up[k][v] = mid ? up[k-1][mid] : 0;
        }
    }
}

int lca(int a, int b) {
    if (!a || !b) return a ^ b; 
    if (depthArr[a] < depthArr[b]) swap(a, b);
    int diff = depthArr[a] - depthArr[b];
    for (int k = 0; diff; ++k, diff >>= 1) {
        if (diff & 1) a = up[k][a];
    }
    if (a == b) return a;
    for (int k = LOGN-1; k >= 0; --k) {
        if (up[k][a] != up[k][b]) {
            a = up[k][a];
            b = up[k][b];
        }
    }
    return up[0][a];
}

int dist(int a, int b) {
    int c = lca(a, b);
    return depthArr[a] + depthArr[b] - 2 * depthArr[c];
}

inline bool on_path(int a, int b, int c) {

    return dist(a, b) == dist(a, c) + dist(c, b);
}


void add_to(Core &st, int x) {
    if (st.empty) {
        st.empty = false;
        st.ok = true;
        st.u = st.v = x;
        return;
    }
    if (!st.ok) return; 

    int u = st.u, v = st.v;
    if (on_path(u, v, x)) {

        return;
    }

    if (on_path(x, u, v)) {

        st.v = x;
        return;
    }
    if (on_path(x, v, u)) {

        st.u = x;
        return;
    }

    st.ok = false;
}


struct StackDS {
    struct Snap {
        int u, v;
        unsigned char flags; 
        Snap() {}
        Snap(int _u,int _v,bool ok,bool empty){
            u=_u; v=_v;
            flags = (ok?1:0) | (empty?2:0);
        }
    };

    vector<int> vals;   
    vector<Snap> snaps; 
    Core cur;

    StackDS() {
        cur.u = cur.v = 0;
        cur.ok = true;
        cur.empty = true;
    }

    void push(int x) {
        vals.push_back(x);
        snaps.emplace_back(cur.u, cur.v, cur.ok, cur.empty);
        add_to(cur, x);
    }

    int pop() {
        if (vals.empty()) return -1;
        int x = vals.back(); vals.pop_back();
        Snap s = snaps.back(); snaps.pop_back();
        cur.u = s.u; cur.v = s.v;
        cur.ok = s.flags & 1;
        cur.empty = (s.flags & 2) != 0;
        return x;
    }

    bool empty() const { return vals.empty(); }
};

Core mergeCore(const Core &A, const Core &B) {
    if (A.empty) return B;
    if (B.empty) return A;
    if (!A.ok || !B.ok) {
        Core res;
        res.u = res.v = 0;
        res.ok = false;
        res.empty = false;
        return res;
    }
    Core res = A; 
    add_to(res, B.u);
    add_to(res, B.v);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs_build(1);

    StackDS frontSt, backSt; // in, out 两个栈

    string ans;
    ans.reserve(q); // 最多那么多 3 型操作

    for (int i = 0; i < q; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int x; cin >> x;
            backSt.push(x);
        } else if (op == 2) {
        
            if (frontSt.empty()) {

                while (!backSt.empty()) {
                    int x = backSt.pop();
                    frontSt.push(x);
                }
            }
            if (!frontSt.empty()) {
                frontSt.pop(); 
            }
        } else if (op == 3) {

            Core res = mergeCore(frontSt.cur, backSt.cur);

            bool ok = res.empty ? true : res.ok;
            ans.push_back(ok ? '1' : '0');
        }
    }

    cout << ans << '\n';
    return 0;
}
