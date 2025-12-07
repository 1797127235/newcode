#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node
{
    int cost = 0;
    int base = 0;
    int bonus = 0;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, S;
    if (!(cin >> n >> S)) return 0;

    vector<node> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].cost >> v[i].base >> v[i].bonus;
    }

    const long long INF = (1LL << 60);
    vector<long long> dp(S + 1, INF);
    dp[0] = 0;

    //背包
    for (int i = 1; i <= n; i++)
    {
        int cost = v[i].cost;
        int base = v[i].base;
        int bonus = v[i].bonus;

        if (cost >= 5000) continue;

        int first_val = base + bonus;
        if (first_val > 0)
        {
            for (int s = S; s >= 0; --s)
            {
                if (dp[s] == INF) continue;
                int ns = s + first_val;
                if (ns > S) ns = S; 
                dp[ns] = min(dp[ns], dp[s] + cost);
            }
        }

        if (base > 0)
        {
            for (int s = 0; s <= S; ++s)
            {
                if (dp[s] == INF) continue;
                int ns = s + base;
                if (ns > S) ns = S;
                long long nc = dp[s] + cost;
                if (nc < dp[ns]) dp[ns] = nc;
            }
        }
    }
    if (dp[S] == INF)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n" << dp[S] << '\n';
    }

    return 0;
}