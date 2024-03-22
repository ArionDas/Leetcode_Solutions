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
    bool isPalindrome(ListNode* head) {
        if(!head->next) return 1;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast)
            slow = slow->next; // in odd lists, no need to check middle element
        ListNode* low = NULL;
        ListNode* mid = slow;
        ListNode* high = NULL;
        while(mid) {
            high = mid->next;
            mid->next = low;
            low = mid;
            mid = high;
        }
        slow = low;
        while(slow) {
            if(head->val != slow->val)
                return 0;

            slow = slow->next;
            head = head->next;
        }
        return 1;
    }
};