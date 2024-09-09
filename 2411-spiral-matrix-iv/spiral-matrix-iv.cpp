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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<int> temp(n,-1);
        vector<vector<int>> ans(m,temp);

        int top=0,bottom=m-1,left=0,right=n-1;
        ListNode* tmp = head;
        while(top<=bottom && left<=right && tmp) {
            for(int i=left; i<=right&&tmp; i++) {
                ans[top][i]=tmp->val;
                tmp=tmp->next;
            }
            top+=1;

            for(int i=top; i<=bottom&&tmp; i++){
                ans[i][right]=tmp->val;
                tmp=tmp->next;
            }
            right-=1;

            if(left<=right) {
                for(int i=right; i>=left&&tmp; i--) {
                    ans[bottom][i]=tmp->val;
                    tmp=tmp->next;
                }
                bottom-=1;
            }

            if(top<=bottom) {
                for(int i=bottom; i>=top&&tmp; i--) {
                    ans[i][left]=tmp->val;
                    tmp=tmp->next;
                }
                left+=1;
            }
        }
        return ans;
    }
};