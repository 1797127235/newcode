//https://leetcode.cn/problems/count-operations-to-obtain-zero/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        while(num1 !=0 && num2 != 0)
        {
            if(num1 > num2)
            {
                ans = ans + num1 / num2;
                num1 %= num2;
            }
            else
            {
                ans = ans + num2 / num1;
                num2 %= num1;
            }
        }
        return ans;      
    }
};