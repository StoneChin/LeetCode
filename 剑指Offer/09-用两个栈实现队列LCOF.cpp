/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


#include <stack>
using namespace std;

class CQueue {
public:
    stack<int> stk1;
    stack<int> stk2;
    CQueue() {

    }
    
    void appendTail(int value) {
        stk1.push(value);
    }
    
    int deleteHead() {
        /* 优化前
        int tmp;
        if(!stk2.empty()){
            tmp = stk2.top();
            stk2.pop();
        }
        // stk2 = empty
        else{
            if(!stk1.empty()){
                while(!stk1.empty()){
                    stk2.push(stk1.top());
                    stk1.pop();
                }
                tmp = stk2.top();
                stk2.pop();
            }
            else return -1;
        }
        return tmp;
        */

       // 优化后，首先判断stk2空的情况，然后整合pop操作
       if(stk2.empty()){
           if(stk1.empty()){
               return -1;
           }
           // stk2空的时候while循环将stk1中的元素压入到stk2中
           while(!stk1.empty()){
                stk2.push(stk1.top());
                stk1.pop();
            }
       }
       int tmp = stk2.top();
       stk2.pop();
       return tmp;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */