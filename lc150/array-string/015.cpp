// 380. O(1) 时间插入、删除和获取随机元素
#include "../def.h"

// 哈希+可变数组
// 哈希值为对应 index
// 处理删除问题：将对应 index 与 last 交换，pop_back 删除 last

class RandomizedSet {
public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if (m.count(val)) {
            return false;
        }

        int index = v.size();
        v.emplace_back(val);
        m[val] = index;
        return true;
    }
    
    bool remove(int val) {
        if (!m.count(val)) {
            return false;
        }

        int index = m[val];

        int last = v.back();

        // swap last
        v[index] = last;
        m[last] = index;
        // pop
        v.pop_back();
        m.erase(val);

        return true;
    }
    
    int getRandom() {
        return v[(rand() % v.size())];
    }
private:
    unordered_map<int, int> m;
    vector<int> v;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */