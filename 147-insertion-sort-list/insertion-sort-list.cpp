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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* curr = head;
        while(curr != NULL) {
            ListNode* temp = curr->next;
            ListNode* min = curr;
            while(temp!=NULL) {
                if(min->val > temp->val)
                    min = temp;
                temp = temp->next;
            }
            int p = min->val;
            min->val = curr->val;
            curr->val = p;
            curr = curr->next;
        }
        return head;
    }
};