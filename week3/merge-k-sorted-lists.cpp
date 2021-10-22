//23. 合并K个升序链表
//https://leetcode-cn.com/problems/merge-k-sorted-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return {};

        return mergeRecur(lists, 0, lists.size() - 1);
    }

private:
    ListNode* mergeRecur(vector<ListNode*>& lists, int left, int right) {
        ListNode head;
        ListNode* p = &head;

        if (left == right) return lists[left];

        ListNode* a = mergeRecur(lists, left, left + (right - left) / 2);
        ListNode* b = mergeRecur(lists, (left + (right - left) / 2) + 1, right);

        while (a || b) {
            if (!b || (a && a->val <= b->val)) {
                p->next = a;
                a = a->next;
            } else {
                p->next = b;
                b = b->next;
            }
            p = p->next;
        }

        return head.next;
    }
};