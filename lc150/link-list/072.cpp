// 92. 反转链表 II
#include "../def.h"

// 增加头结点 + 双指针

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 增加空的首/尾结点
        ListNode* newHead = new ListNode(0);
        newHead->next = head;

        int i=0;
        ListNode* start = newHead, *prev;
        while (i<left) {
            prev = start;
            start = start->next;
            i++;
        }

        // 双指针，后插
        ListNode* tail = start;
        while (i < right) {
            tail = tail->next;
            i++;
        }

        // prev - start - tail
        while (start != tail) {
            prev->next = start->next;
            start->next = tail->next;
            tail->next = start;

            start = prev->next;
        }
        

        return newHead->next;
    }
};