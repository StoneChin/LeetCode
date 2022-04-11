class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // 使用了很朴素的递归
        // if(n == 0) return 1;
        // // 遇到大于11位的数根据抽屉原理
        // if(n > 10) return -1;
        // int c = 9;
        // int now = 9;
        // for(int i = 0;i<n-1;i++){
        //     c *= now;
        //     now--;
        // }
        // return countNumbersWithUniqueDigits(n-1)+c;

        //代码优化以后
        int res = 1;
        int now = 9;
        for(int i = 1; i < 10 && i <= n; i++){
            res += now;
            now *= (10-i);
        }
        return res;
    }
};