#include <iostream>
#include <unordered_map>

using namespace std;
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> map;
        for(char c : s){
            map[c]++;
        }
        for(char c : s){
            if(map[c] == 1)
                return c;
        }
        return ' ';
    }
};