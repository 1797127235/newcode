#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 0x3f3f3f3f3f3f3f3f;

struct node {
    string s;
    int id; //题目编号
    int t;
    string state;
};

void eachT() {
    int n;
    cin >> n;
    map<string, int> mp;
    vector<array<int, 26>> problems; //该队伍是否已解某题
    vector<array<int, 26>> penalty; //该队伍该题罚时
    int cnt = 0; //表示总的队伍数

    vector<node> a(n);

    for (int i = 0; i < n; i++) {
        string s;
        char id;
        int t;
        string state;
        cin >> s >> id >> t >> state;
        a[i] = { s, id - 'A', t, state };
    }
    //按照题目提交时间排序
    sort(a.begin(), a.end(), [&](const node& A, const node& B) { 
        return A.t < B.t;
    });

    int p = n; 

    //枚举每个提交记录
    for (int i = 0; i < n; i++)
    {
        auto& [s, id, t, state] = a[i];
        if (!mp.count(s)) {
            mp[s] = cnt++;
            problems.push_back({});
            penalty.push_back({});
        }

        int duiwu = mp[s]; //第几支队伍

        if (state == "Unknown") {  //记录第一个unknown提交的位置,直接退出
            p = i; 
            break;
        }

        if (state == "Accepted") {
            if (problems[duiwu][id] == 0) {
                problems[duiwu][id] = 1;
                penalty[duiwu][id] += t;
            }
        } else if (state == "Rejected") {
            if (problems[duiwu][id] == 0) {
                penalty[duiwu][id] += 20;  //没有解决某题时，拒绝才加罚时
            }
        }
    }

    map<string, int> all_problems;  //冻结前每个队伍解决的题数
    map<string, int> all_penalty;  //冻结前每个队伍罚时

    map<string, vector<node>> mp2; //冻结后的unknow提交

    for (int i = p; i < n; i++) {
        auto [s, id, t, state] = a[i];
        if (!mp.count(s)) {
            mp[s] = cnt++;
            problems.push_back({});
            penalty.push_back({});
        }

        mp2[s].push_back(a[i]);
    }

    for (auto [s, duiwu] : mp) {
        for (int i = 0; i < 26; i++) {
            if (problems[duiwu][i] == 1) {  //这个队伍解决了该题
                all_penalty[s] += penalty[duiwu][i];
                all_problems[s] += 1;
            }
        }
    }



    int MAX_problems = 0;
    int MIN_penalty = inf;

    for (auto [s, duiwu] : mp) {
        if (all_problems[s] > MAX_problems) {
            MAX_problems = all_problems[s];
            MIN_penalty = all_penalty[s];
        } else if (all_problems[s] == MAX_problems) {
            if (all_penalty[s] < MIN_penalty) {
                MIN_penalty = all_penalty[s];
            }
        }
    }

    vector<string> ans;

    for (auto [s, duiwu] : mp) {
        auto pros = problems[duiwu]; //array<int,26> 该队伍是否已解某题
        auto pens = penalty[duiwu]; //array<int,26> 该队伍该题罚时

        int pro = all_problems[s];
        int pen = all_penalty[s];

        if (pro == MAX_problems && pen == MIN_penalty) {
            ans.push_back(s);
            continue;
        }

        for (auto [name, id, t, state] : mp2[s]) {
            if (pros[id] == 0) {
                pros[id] = 1;
                pro += 1;
                pen += pens[id];
                pen += t;
            }
        }

        if (pro > MAX_problems) {
            ans.push_back(s);
        } else if (pro == MAX_problems) {
            if (pen <= MIN_penalty) {
                ans.push_back(s);
            }
        }
    }

    for (auto s : ans) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        eachT();
    }

    return 0;
}