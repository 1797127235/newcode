#include<bits/stdc++.h>
using namespace std;


class Bank {
public:
    Bank(vector<long long>& balance) {
        _balance = balance;
        _n = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 < 1 || account1 > _n || account2 < 1 || account2 > _n)
            return false;
        if(_balance[account1 - 1] < money)
            return false;
        _balance[account1 - 1] -= money;
        _balance[account2 - 1] += money;
        return true;
    
    }
    
    bool deposit(int account, long long money) {
        if(account < 1 || account > _n)
            return false;
        _balance[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account < 1 || account > _n)
            return false;
        if(_balance[account - 1] < money)
            return false;
        _balance[account - 1] -= money;
        return true;
    }


    vector<long long> _balance;
    int _n;
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */