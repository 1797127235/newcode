// https://leetcode.cn/problems/xor-operation-in-an-array/
#include<bits/stdc++.h>
using namespace std;

//模拟
class Solution1 {
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

    0到n的异或和推导 
    没4个连续数的异或和是0
    n = 4 * k  此时有 4 *k + 1 个数 最后一个数是答案

    n = 4 * k + 1 此时有 4 * k + 2 个数 倒数第二个数是答案 为1

    n = 4 * k + 2 此时有 4 * k + 3 个数 倒数第三个数是答案 为 n + 1

    n = 4 * k + 3 此时有 4 * k + 4 个数 全部抵消为0
*/


class Solution2 {
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