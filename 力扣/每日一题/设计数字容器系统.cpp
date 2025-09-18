#include<bits/stdc++.h>

using namespace std;


class NumberContainers {
    unordered_map<int, int> index_to_number; //下标到值的映射
    unordered_map<int, set<int>> number_to_indices; //值到下标的映射

public:
    void change(int index, int number) {
        // 移除旧数据
        auto it = index_to_number.find(index);
        if (it != index_to_number.end()) {
            number_to_indices[it->second].erase(index);
        }

        // 添加新数据
        index_to_number[index] = number;
        number_to_indices[number].insert(index);
    }

    int find(int number) {
        auto it = number_to_indices.find(number);
        return it == number_to_indices.end() || it->second.empty() ? -1 : *it->second.begin();
    }
};
