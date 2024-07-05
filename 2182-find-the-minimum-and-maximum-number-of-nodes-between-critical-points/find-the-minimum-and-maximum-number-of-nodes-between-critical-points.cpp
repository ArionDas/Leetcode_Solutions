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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> distances;

        ListNode* temp = head->next;
        ListNode* prev = head;
        int k = 2;

        while(temp->next) {
            if((prev->val < temp->val && temp->val > temp->next->val) || (prev->val > temp->val && temp->val < temp->next->val))
                distances.push_back(k);
            temp = temp->next;
            prev = prev->next;
            k += 1;
        }
        //cout << distances.size() << endl;
        if(distances.size() < 2)
            return {-1,-1};

        int max_distance = INT_MIN, min_distance = INT_MAX;
        int len = distances.size();
        for(int i=1; i<len; i++) {
            //max_distance = max(max_distance, distances[i] - distances[i-1]);
            min_distance = min(min_distance, distances[i] - distances[i-1]);
        }
        max_distance = distances[len-1] - distances[0];

        return {min_distance, max_distance};
    }
};