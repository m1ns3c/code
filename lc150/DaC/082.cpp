// 148. 排序链表
#include "../def.h"

// 升序

// 每次头插，都需要重复遍历 O(n^2)
// 分治 局部有序

// O(n logn) 快排[数|链] 堆排[数组] 希尔[数|链] 归并[数|链]
// O(n) 遍历一次
// O(log n) 二分查找/分治


// 归并排序
// 快慢指针 快+2 慢+1

// 1.自顶向下（找中点）


// 2.自底向上
// O(1) 空间
// 每次 2 倍向上合并

class Solution {
public:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);

        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val < temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }

        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }

        return dummyHead->next;
    }

    ListNode* sortList(ListNode* head) {
        // 如何计算长度 n
        // 递归一次
        return sortList(head, nullptr);
    }
    
    ListNode* sortList(ListNode* head, ListNode* tail) {
        // 0个结点
        if (head == nullptr) {
            return head;
        }
        // 1个结点
        if (head->next == tail) {
            head->next = nullptr;   // 截断链表
            return head;
        }

        ListNode* fast = head, *slow = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        ListNode* mid = slow;

        // [head, mid), [mid, tail)
        return merge(sortList(head, mid), sortList(mid, tail));
    }
};