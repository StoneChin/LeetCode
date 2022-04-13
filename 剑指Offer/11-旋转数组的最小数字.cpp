#include <vector>

using namespace std;
class Solution {
public:
    int minArray(vector<int>& numbers) {
        // 暴力的方法
        // for(int i = 0;i < numbers.size()-1;i++){
        //     if(numbers[i] > numbers[i+1])
        //         return numbers[i+1];
        // }
        // return numbers[0];

        // 使用二分查找的方法进行判断
        int low = 0;
        int high = numbers.size() - 1;
        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (numbers[pivot] < numbers[high]) {
                high = pivot;
            }
            else if (numbers[pivot] > numbers[high]) {
                low = pivot + 1;
            }
            else {
                high -= 1;
            }
        }
        return numbers[low];
    }
};