#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int> >& matrix, int target) {
        // 可以看作一个搜索树，其中root为最右上方的值
        // int n = matrix.size();
        // if(n == 0) return false;
        // int m = matrix[0].size();
        // int i = 0, j = m-1;
        // while(i < n && j >= 0){
        //     if(target > matrix[i][j]) i++;
        //     else if(target < matrix[i][j]) j--;
        //     else return true;
        // }
        // return false;

    // 优化由于m未必存在，因此不必求出来，只需要指定i，j然后判断while即可
        int i = matrix.size() - 1, j = 0;
        while(i >= 0 && j < matrix[0].size())
        {
            if(matrix[i][j] > target) i--;
            else if(matrix[i][j] < target) j++;
            else return true;
        }
        return false;
    }
};