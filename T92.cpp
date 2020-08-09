/******************************
 * LeetCode 第92题，链表局部反转
 * Date：2020-08-09
 *****************************/
#include <iostream>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode myHead(0);
        ListNode* myhead = &myHead;     // 在所给链表前插入一个没有数据意义的头结点
                                        // 以应对从第一个元素开始反转的情况
        myhead->next = head;
        ListNode* nodeNow = myhead;
        ListNode* nodeLast = nullptr;
        int pos_now = 0;
        for( ; nodeNow!=nullptr;){
            if(pos_now == m){
                ListNode* beforeM = nodeLast;
                ListNode* afterN = nodeNow;
                ListNode* temp = nodeNow->next;     // 注意这个temp的作用
                for(; pos_now < n; pos_now++){
                    ListNode* nodeNext = temp;
                    temp = nodeNext->next;
                    nodeNext->next = nodeNow;
                    nodeNow = nodeNext;         // 核心只有这几行代码

                }
                beforeM->next = nodeNow;
                afterN->next = temp;
                break;
            }
            else{
                pos_now++;
                nodeLast = nodeNow;
                nodeNow = nodeNow->next;
            }
        }
        return myhead->next;

    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
