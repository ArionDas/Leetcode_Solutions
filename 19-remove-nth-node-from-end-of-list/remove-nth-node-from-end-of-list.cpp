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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy_node = new ListNode();
        dummy_node->next = head;

        ListNode* fast = dummy_node;
        ListNode* slow = dummy_node;

        if(head->next == NULL) {
            return NULL;
        }
        int len=0;
        for(int i=1; i<=n; i++) {
            fast = fast->next;
            len++;
        }

        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
            len++;
        }

        slow->next = slow->next->next;
        if(len==n)
            return head->next;
        return head;
    }
};