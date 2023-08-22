// 427. 建立四叉树
#include "../def.h"

// 分治递归合并

class Solution {
public:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);

        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val > temp2->val) {
                temp->next = temp2;
                temp2 = temp2->next;
            } else {
                temp->next = temp1;
                temp1 = temp1->next;
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

    ListNode* dac(vector<ListNode*>& lists, int begin, int end) {
        if (begin == end) {
            return lists[begin];
        }
        if (begin > end) {
            return nullptr;
        }
        int mid = (begin + end) >> 1;
        return merge(dac(lists, begin, mid), dac(lists, mid+1, end));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 合并 k 个
        // 合并 k-1 k
        // (1, 2), 3), 4)
        // ((1, 2) (3, 4))
        // 分治
        return dac(lists, 0, lists.size()-1);
    }
};