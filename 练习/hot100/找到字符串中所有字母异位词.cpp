#include<bits/stdc++.h>

using namespace std;


//定长滑窗
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        array<int, 26> cnt_p{}; // 统计 p 的每种字母的出现次数
        array<int, 26> cnt_s{}; // 统计 s 的长为 p.length() 的子串 s' 的每种字母的出现次数
        for (char c : p) {
            cnt_p[c - 'a']++;
        }

        for (int right = 0; right < s.length(); right++) {
            cnt_s[s[right] - 'a']++; // 右端点字母进入窗口
            int left = right - p.length() + 1;
            if (left < 0) { // 窗口长度不足 p.length()
                continue;
            }
            if (cnt_s == cnt_p) { // s' 和 p 的每种字母的出现次数都相同
                ans.push_back(left); // s' 左端点下标加入答案
            }
            cnt_s[s[left] - 'a']--; // 左端点字母离开窗口
        }
        return ans;
    }
};


//不定长滑窗
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int cnt[26]{}; // 统计 p 的每种字母的出现次数
        for (char c : p) {
            cnt[c - 'a']++;
        }

        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            int c = s[right] - 'a';
            cnt[c]--; // 右端点字母进入窗口
            //保证s中某个字母出现次数《=p中某个字母出现次数
            //如果s中某个字母出现次数比p少 证明s的总长度一定《=p的长度
            while (cnt[c] < 0) { // 字母 c 太多了
                cnt[s[left] - 'a']++; // 左端点字母离开窗口
                left++; 
            }

            if (right - left + 1 == p.length()) { // s' 和 p 的每种字母的出现次数都相同
                ans.push_back(left); // s' 左端点下标加入答案
            }
        }
        return ans;
    }
};

