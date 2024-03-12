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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode*> um;
        int prefsum = 0;

        for(ListNode* current = dummy; current!=NULL; current = current->next) {
            prefsum += current->val;
            if(um.find(prefsum)!=um.end()) {
                ListNode* prev = um[prefsum];
                ListNode* remove = prev->next;
                int p = prefsum + (remove?remove->val:0);

                while(p!=prefsum) {
                    um.erase(p);
                    remove = remove->next;
                    p += remove ? remove->val:0;
                }
                prev->next = current->next;
            }
            else {
                um[prefsum] = current;
            }
        }
        return dummy->next;
    }
};