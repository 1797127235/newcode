//http://47.117.109.207/problem.php?id=1572


#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n;
    cin >> n;

    /*
        x右移一位后的每一位都与原来x不同
    */
    long long ans = 0;

    if(n % 2 == 0)
    {
        for(int i = 0; i < n; ++i)
        {
            if(i % 2)
            {
                ans |= (1LL << i);
            }
        }
    }
    else
    {
        for(int i = 0; i < n; ++i)
        {
            if(i % 2 == 0)
            {
                ans |= (1LL << i);
            }
        }
    }

    cout << ans << endl;

}