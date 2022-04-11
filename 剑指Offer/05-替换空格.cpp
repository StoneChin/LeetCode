// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

#include <iostream>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string res;
        // C++11 容器的for循环
        for(char c : s){
            if(c == ' ') res += "%20";
            else res += c;
        }
        return res;
    }
};