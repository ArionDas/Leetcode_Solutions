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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* prev = head;
        int value = 0;
        while(temp) {
            value += temp->val;
            if(temp->val == 0) {
                prev->next = new ListNode(value);
                value = 0;
                prev = prev->next;
            }
            temp = temp->next;
        }
        
        return head->next;
    }
};