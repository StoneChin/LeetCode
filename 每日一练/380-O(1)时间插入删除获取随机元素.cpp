#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class RandomizedSet {
public:
    // 用于getRandom使用
    vector<int> nums;
    unordered_map<int, int> map;

    RandomizedSet() {
        // 初始化随机数生成器
        srand(time(0));
    }
    
    bool insert(int val) {
        if(map.count(val))
            return false;
        int index = nums.size();
        nums.push_back(val);
        // map[val]记录了val在nums中的下标
        map[val] = index;
        return true;
    }
    
    bool remove(int val) {
        if(!map.count(val))
            return false;
        int index = map[val];
        int last = nums.back();// 把最后一个数给找出来，将要弹出的数交换到最后的位置然后弹出
        nums[index] = last;
        map[last] = index;
        nums.pop_back();
        map.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */