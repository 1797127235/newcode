// https://leetcode.cn/problems/xor-operation-in-an-array/
#include<bits/stdc++.h>
using namespace std;

//模拟
class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0;
        for(int i = 0 ; i < n;i++)
        {
            ans = ans ^(start + 2 * i);
        }
        return ans;
    }
};


//数学

/*
    0 到 n的异或和
    如果 n % 4 == 0 结果是 n
    如果 n % 4 == 1 结果是 1
    如果 n % 4 == 2 结果是 n + 1
    如果 n % 4 == 3 结果是 0

    nums[i] = start + 2*i = start & 1 + 2 * (start /2 + i)
*/


class Solution {
    int xor_n(int n) {
        switch (n % 4) {
            case 0: return n;
            case 1: return 1;
            case 2: return n + 1;
            default: return 0;
        }
    }

public:
    int xorOperation(int n, int start) {
        int a = start / 2;
        int b = n & start & 1; // 只有当 n 为奇数且 start 的最低位为 1，最低位异或才为 1
        return (xor_n(a + n - 1) ^ xor_n(a - 1)) * 2 + b;
    }
};