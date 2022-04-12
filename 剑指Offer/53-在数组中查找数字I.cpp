// 统计一个数字在排序数组中出现的次数。

#include <vector>

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = 0;
        int mid = findMid(nums, target);
        if(mid >= 0) res = 1;
        int i = mid+1, j = mid-1;
        while(i < nums.size() && nums[i]==target){
            res++;
            i++;
        }
        while(j >= 0 && nums[j] == target){
            res++;
            j--;
        } 
        return res;
    }

    int findMid(vector<int> nums, int target){
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int mid  = (l+r)/2;
            if(nums[mid] < target) l = mid+1;
            else if(nums[mid] > target) r = mid-1;
            else return mid;
        }
        return -1;
    }
};