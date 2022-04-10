/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <iostream>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        for(Node* newhead = head;newhead != nullptr;newhead = newhead->next->next){
            Node* midHead = new Node(newhead->val);
            midHead->next = newhead->next;
            newhead -> next = midHead;
        }
        for(Node* newhead = head;newhead != nullptr;newhead = newhead->next->next){
            Node *midHead = newhead->next;//表示当前指向的节点的下一个节点
            midHead->random = (newhead->random == nullptr)?nullptr:newhead->random->next;
        }
        Node *head2 = head->next;
        for(Node* newhead = head;newhead != nullptr;newhead = newhead->next){
            Node *midHead = newhead->next;
            newhead->next = newhead->next->next;//写成newhead->next = newhead->next->next会更方便理解
            midHead->next = (midHead->next==nullptr)?nullptr : midHead->next->next;
        }
        return head2;
    }
};