#include<iostream>
#include<algorithm>
#include<list>
#include<unordered_map>
using namespace std;

class LRUCache{
private:
    int _capacity;
    list<pair<int,int>> cache_list; // 双向链表存储缓存数据
    unordered_map<int, list<pair<int,int>>::iterator> cache_map; // 哈希表

public:
    LRUCache(int capacity):_capacity(capacity) {}
    int get(int key)
    {
        if(cache_map.find(key) == cache_map.end())
            return -1; 

        // 将该节点移到链表头部
        auto it = cache_map[key];
        //目标位置，原链表，移动的节点
        cache_list.splice(cache_list.begin(), cache_list, it);

        return it->second;
    }

    void put(int key, int value)
    {
        if(cache_map.find(key) != cache_map.end())
        {
            // 更新节点值并移到链表头部
            auto it = cache_map[key];
            it->second = value;
            cache_list.splice(cache_list.begin(), cache_list, it);
        }
        else
        {
            if(cache_list.size() == _capacity)
            {
                // 删除链表尾部节点
                auto last = cache_list.back();
                cache_map.erase(last.first);
                cache_list.pop_back();
            }
            // 插入新节点到链表头部
            cache_list.emplace_front(key, value);
            cache_map[key] = cache_list.begin();
        }
    }



};