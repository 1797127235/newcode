#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
       set<char> st = {'a','e','i','o','u','A','E','I','O','U'};

       string t = "";

       for(auto &c : s)
       {
            if(st.count(c)) t += c;
       }
       sort(t.begin(),t.end());


       string ans = "";
       int i = 0;
       for(auto &c : s)
       {
        if(st.count(c))
        {
            ans += t[i];
            i++;
        }
        else
        {
            ans += c;
        }
       }
       return ans ; 
    }
};