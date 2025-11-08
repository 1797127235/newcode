//https://leetcode.cn/problems/duplicate-zeros/description/
#include<bits/stdc++.h>
using namespace std;
/*
    双指针
    先遍历一遍统计数组中零的个数
    设原数组末尾下表  i = n - 1,目标写入位置 j = n - 1 + z(这是理想扩容后的末尾下标，超出n - 1 的部分等价于越界丢弃)
    从右往左同时移动i,j
    把arr[i] 写到 位置 j(假如条件满足)
    如果arr[i] == 0,写两次
*/
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        long long zeros = 0;
        for (int& v : arr) if (v == 0) ++zeros;

        int i = n - 1;
        long long j = n - 1 + zeros; 
        while (i >= 0 && j >= 0) {
            if (j < n) arr[j] = arr[i];
            if (arr[i] == 0) {
                --j;
                if (j < n && j >= 0) arr[j] = 0; 
            }
            --i;
            --j;
        }
    }
};