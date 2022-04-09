/*
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    // 辅助栈存储最小值
    stack<int> stk;
    stack<int> minStk;
    MinStack() {
        // 优化
        minStk.push(INT_MAX);
    }
    
    void push(int x) {
        stk.push(x);
        // 优化前，需要对minStk辅助栈是否空进行判断
        // if(minStk.empty()) minStk.push(x);
        // else{
        //     if(x <= minStk.top()) minStk.push(x);
        // }

        // 优化后
        if(x <= minStk.top()) minStk.push(x);
    }
    
    void pop() {
        if(stk.top() == minStk.top()) minStk.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int min() {
        return minStk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */